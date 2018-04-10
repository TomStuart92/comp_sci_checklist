#include <stdio.h>
#include <stdbool.h>
#include "Queue.h"

#define MAX_VERTICES 10

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int number_of_vertices;

bool isBipartite(int G[number_of_vertices][number_of_vertices], int src);

bool isBipartite(int G[number_of_vertices][number_of_vertices], int src)
{
  int colorArray[number_of_vertices];
  for(int i = 0; i < number_of_vertices; i++)
    colorArray[i] = -1;   // assign no color to all vertices;

  colorArray[src] = 1;  // assign first color to source. 

  struct Queue* queue = createQueue(number_of_vertices);
  enqueue(queue, src);

  while(!isEmpty(queue)) 
  {
    int vertex = dequeue(queue);

    // check if there is a cycle. 
    if(G[vertex][vertex] == 1)
      return false;

    for(int neighbour = 0; neighbour < number_of_vertices; neighbour++)
    {
      // if neighbour doesn't have a color, assign it opposite color to vertex.
      if(G[vertex][neighbour] && colorArray[neighbour] == -1)
      {
        colorArray[neighbour] = 1 - colorArray[vertex];
        enqueue(queue, neighbour);
      } 
      else if (G[vertex][neighbour] && colorArray[vertex] == colorArray[neighbour]) 
        return false; // neighbour already is colored same as vertex;
    }
  }
  return true;    // all vertices have been colored.
}


int main() 
{
  printf("Enter number of vertices:\n");  
  scanf("%d",&number_of_vertices);

  if (number_of_vertices > MAX_VERTICES) {
    printf("%d is greater than the maximum number of vertices, %d\n", number_of_vertices, MAX_VERTICES);
    return 1;
  }

  printf("\nEnter adjecency matrix of the graph:\n");   
  for(int i=0; i < number_of_vertices; i++)
    for(int j=0; j < number_of_vertices; j++)
      scanf("%d", &adjacency_matrix[i][j]);

  isBipartite(adjacency_matrix, 0) ? printf("\nGraph is Bipartite\n") : printf("\nGraph is Not Bipartite\n");
  return 0;
}