#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Edge
{
  int src;
  int dest;
  int weight;
};

struct Graph 
{
  int V;
  int E;
  struct Edge* edge;
};

void printArray(int array[], int length);
struct Graph* createGraph(int V, int E);
void BellmanFord(struct Graph* graph, int src);

void printArray(int array[], int length)
{
  for (int i = 0; i < length; ++i)
    printf("%d \t\t %d\n", i, array[i]);
}

struct Graph* createGraph(int V, int E)
{
  struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));
  graph->V = V;
  graph->E = E;

  graph->edge = (struct Edge*) malloc( sizeof(struct Edge));
  return graph;
}

void BellmanFord(struct Graph* graph, int src)
{
  int V = graph->V;
  int E = graph->E;

  int dist[V];

  for(int i = 0; i < V; i++)
    dist[i] = INT_MAX;

  dist[src] = 0;

  for(int i = 1; i <= V-1; i++)
  {
    for(int j = 0; j < E; j++)
    {
      int u = graph->edge[j].src;
      int v = graph->edge[j].dest;
      int weight = graph->edge[j].weight;

      if(dist[u] + weight < dist[v])
        dist[v] = dist[u] + weight; 
    }
  }

  for(int i = 0; i < E; i++)
  {
    int u = graph->edge[i].src;
    int v = graph->edge[i].dest;
    int weight = graph->edge[i].weight;

    if(dist[u] + weight < dist[v])
      printf("WARN: GRAPH CONTAINS NEGATIVE WEIGHT CYCLE");
  }

  printf("Vertex   Distance from Source\n");
  printArray(dist, V);
  return;
}

int main()
{
  int V = 10;
  int E = 18;
  scanf("%d",&V);
  scanf("%d",&E);

  struct Graph* graph = createGraph(V, E);
  for(int i = 0; i < E; i++) {
    scanf("%d",&graph->edge[i].src);
    scanf("%d",&graph->edge[i].dest);
    scanf("%d",&graph->edge[i].weight);
  }
  BellmanFord(graph, 0);
  return 0;
}