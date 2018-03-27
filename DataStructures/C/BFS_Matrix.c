#include <stdio.h>

#define MAX_VERTICES 10

void DFS(int);

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int number_of_vertices;



void bfs(int v) {
  int number_visited = 0;
  int queue_head = -1;

	for(int i = 1; i <= number_of_vertices; i++)
		if(adjacency_matrix[v][i] && !visited[i])
			queue[++queue_head] = i;

	if(number_visited <= queue_head) {
		visited[queue[number_visited]] = 1;
		bfs(queue[number_visited++]);
	}
}


int main()
{
	printf("\n Enter the number of vertices:");
	scanf("%d", &number_of_vertices);
	for(int i=1; i <= number_of_vertices; i++) {
		queue[i] = 0;
		visited[i] = 0;
	}
	
	printf("\n Enter graph data in matrix form:\n");
	for(int i=1; i<=number_of_vertices; i++) {
		for(int j=1; j<=number_of_vertices; j++) {
			scanf("%d", &adjacency_matrix[i][j]);
		}
	}
	
	printf("\n Enter the starting vertex:");
  int v;
	scanf("%d", &v);
	bfs(v);
	printf("\n The node which are reachable are:\n");
	
	for(int i=1; i <= number_of_vertices; i++) {
		if(visited[i])
			printf("%d\t", i);
		else {
			printf("\n Bfs is not possible. Not all nodes are reachable\n");
			break;
		}
	}
}