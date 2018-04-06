#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 4001
#define BACKLOG 4

const static char* http_response = "HTTP/1.1 200 Ok\r\n"
                                   "Content-Length: 4\r\n"
                                   "\r\n"
                                   "OK\r\n";

const static size_t http_response_len = 42;

typedef enum connection_type {
	CONNECTION_TYPE_CLIENT,
	CONNECTION_TYPE_SERVER
} connection_type_e;

typedef struct server {
  int listen_fd;
} server_t;

typedef struct connection {
	int fd;
	connection_type_e type;
} connection_t;

typedef int (*connection_handler)(connection_t*);

int server_listen(server_t* server);
int server_accept(server_t* server);
connection_t* connection_create(connection_type_e type);
int connection_destroy(connection_t* conn);
int fd_make_nonblocking(int socket);
int http_handler(connection_t* conn);

int http_handler(connection_t* conn)
{
	int  n = 0;
	char buf[1024];

	for (;;) {
		n = read(conn->fd, buf, 1024);
		if (n == -1) {
			if (errno == EAGAIN || errno == EWOULDBLOCK) {
				break;
			}

			perror("read");
			printf("failed to read from the client\n");
			return -1;
		}

		if (n == 0) {
			break;
		}
	}

	n = write(conn->fd, http_response, http_response_len);
	if (n == -1) {
		perror("write");
		printf("failed to write to client\n");
		return -1;
	}

	return 0;
}

int fd_make_nonblocking(int socket)
{
	int err = 0;
	int flags;

	err = (flags = fcntl(socket, F_GETFL, 0));
	if (err == -1) {
		perror("fcntl");
		printf("failed to retrieve socket flags\n");
		return -1;
	}

	flags |= O_NONBLOCK;

	err = fcntl(socket, F_SETFL, flags);
	if (err == -1) {
		perror("fcntl");
		printf("failed to set socket flags\n");
		return -1;
	}

	return 0;
}

int server_listen(server_t* server)
{
  int err = 0;
  struct sockaddr_in server_addr = { 0 };

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htons(INADDR_ANY);
  server_addr.sin_port = htons(PORT);

  // create server
  err = (server->listen_fd = socket(AF_INET, SOCK_STREAM, 0));
  if (err == -1) {
    perror("socket");
    printf("Failed to create socket endpoint\n");
    return err;
  }

  // bind to port
  err = bind(server->listen_fd, (struct sockaddr*) &server_addr, sizeof(server_addr));
  if (err == -1) {
    perror("bind");
    printf("Failed to bind socket to address\n");
    return err;
  }

  // listen on port
  err = listen(server->listen_fd, BACKLOG);
  if (err == -1) {
		perror("listen");
		printf("Failed to put socket in passive mode\n");
		return err;
	}

  return 0;
}

connection_t* connection_create(connection_type_e type) 
{
  connection_t* conn = malloc(sizeof(*conn));
  	if (conn == NULL) {
		perror("malloc");
		printf("failed to allocate memory for connection\n");
		return conn;
	}
	conn->type = type;
	conn->fd   = -1;
	return conn;
}

int connection_destroy(connection_t* conn)
{
	int err;
	if (conn == NULL) {
		return 0;
	}
	if (conn->fd != -1) {
		err = close(conn->fd);
		if (err == -1) {
			perror("close");
			printf("failed to close connection file descriptor\n");
			return -1;
		}
	}
	return 0;
}

int server_accept(server_t* server) 
{
  int err = 0;
  int conn_fd;
  socklen_t client_len;
  struct sockaddr client_addr;
  connection_t* conn;

  client_len = sizeof(client_addr);
  err = (conn_fd = accept(server->listen_fd, &client_addr, &client_len));
  if (err == -1) {
    if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
      return 0;
    }
    perror("accept");
    printf("failed unexpectedly while accepting connection");
    return -1;
  }
  printf("Client connected!\n");

  // Make the incoming socket non-blocking
  fd_make_nonblocking(conn_fd);
  conn = connection_create(CONNECTION_TYPE_CLIENT);
  if (conn == NULL) {
    printf("failed to create connection struct\n");
    return -1;
  }
  conn->fd = conn_fd;

  http_handler(conn);

  err = close(conn_fd);
  if (err == -1) {
    perror("close");
    printf("Failed to close connection\n");
    return err;
  }

	return err;
}


int main() 
{
  int err = 0;
  server_t server = { 0 };
  err = server_listen(&server);

  if(err) {
    printf("Failed to listen on address 0.0.0.0:%d\n", PORT);
    return err;
  }

  for(;;) {
    err = server_accept(&server);
    if(err) {
      printf("Failed accepting connection\n");
      return err;
    }
  }
  return 0;
}