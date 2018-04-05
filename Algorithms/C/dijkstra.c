#include <stdio.h>
// #include <conio.h>

#define INFINITY 9999
#define MAX 10

void dijkstra(int adjacency_matrix[MAX][MAX], int number_of_vertices, int start_node);


void dijkstra(int adjacency_matrix[MAX][MAX], int number_of_vertices, int start_node)
{
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, min_distance, next_node; 

  for(int i = 0; i < number_of_vertices; i++)
    for(int j = 0; j < number_of_vertices; j++)
      if(adjacency_matrix[i][j] == 0)
        cost[i][j] = INFINITY;
      else 
        cost[i][j] = adjacency_matrix[i][j];
  
  for(int i = 0; i < number_of_vertices; i++)
  {
    distance[i] = cost[start_node][i];
    pred[i] = start_node;
    visited[i] = 0;
  }

  distance[start_node] = 0;
  visited[start_node] = 1;
  count = 1;

  while(count < number_of_vertices - 1)
  {
    min_distance = INFINITY;

    for(int i = 0; i < number_of_vertices; i++)
      if(distance[i] < min_distance && !visited[i])
      {
        min_distance = distance[i];
        next_node = i;
      }

      visited[next_node] = 1;
      for(int i = 0; i < number_of_vertices; i++)
        if(!visited[i])
          if(min_distance + cost[next_node][i] < distance[i])
          {
            distance[i] = min_distance + cost[next_node][i];
            pred[i] = next_node;
          }
    count++;
  }

  int j;
  for(int i = 0; i < number_of_vertices; i++)
    if(i != start_node)
    {
      printf("\nDistance of node%d=%d", i, distance[i]);
      printf("\nPath=%d", i);
      j = i;
      do
      {
        j = pred[j];
        printf("<-%d", j);
      } while(j != start_node);
    }

}




int main()
{
  int adjacency_matrix[MAX][MAX];
  int number_of_vertices;
  int start_node;


  printf("Enter no. of vertices:");
  scanf("%d",&number_of_vertices);
  printf("\nEnter the adjacency matrix:\n");
  
  for(int i = 0; i < number_of_vertices; i++)
    for(int j = 0; j < number_of_vertices; j++)
      scanf("%d", &adjacency_matrix[i][j]);
  
  printf("\nEnter the starting node:");
  scanf("%d ",&start_node);
  dijkstra(adjacency_matrix, number_of_vertices, start_node);
  
  return 0;
}
