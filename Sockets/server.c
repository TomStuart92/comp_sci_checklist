#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BACKLOG 4

// https://github.com/cirocosta/hstatic/blob/master/src/

/**
 * Encapsulates the properties of the server.
 */
typedef struct server {
  int listen_fd;
} server_t;


int server_listen(server_t* server);
int server_accept(server_t* server);


int server_listen(server_t* server)
{
  int err = 0;
  struct sockaddr_in server_addr = { 0 };

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
  return 0;

  // listen on port
  err = listen(server->listen_fd, BACKLOG);
  if (err == -1) {
		perror("listen");
		printf("Failed to put socket in passive mode\n");
		return err;
	}

  return 0;
}

int server_accept(server_t* server) 
{
  return 0;
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