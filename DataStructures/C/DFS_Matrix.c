#include <stdio.h>

#define MAX_VERTICES 10

void DFS(int);

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int number_of_vertices;

void DFS(int start)
{
  printf("\n%d", start);
  visited[start] = 1;

  for(int j = 0; j < number_of_vertices; j++)
    if(!visited[j] && adjacency_matrix[start][j] == 1)
      DFS(j);
}


int main()
{
  printf("Enter number of vertices:");  
  scanf("%d",&number_of_vertices);

  printf("\nEnter adjecency matrix of the graph:");   
  for(int i=0; i < number_of_vertices; i++)
      for(int j=0; j < number_of_vertices; j++)
          scanf("%d", &adjacency_matrix[i][j]);
 
  for(int i=0; i < number_of_vertices; i++)
    visited[i]=0;
 
  DFS(0);
  return 0;
}