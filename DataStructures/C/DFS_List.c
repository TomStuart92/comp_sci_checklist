#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 20

typedef struct node
{
    struct node *next;
    int vertex;
} node;
 
int number_of_vertices;
node* adjacency_list[MAX_VERTICES];   
int visited[MAX_VERTICES];

void read_graph(); 
void insert(int,int);
void DFS(int);

void DFS(int i)
{
    printf("%d\n",i);

    node* p = adjacency_list[i];
    visited[i] = 1;

    while(p != NULL)
    {
       i = p->vertex;
       
       if(!visited[i])
          DFS(i);
        p = p->next;
    }
}
 
void read_graph()
{
    int i, vi, vj, no_of_edges;
    printf("Enter number of vertices:");
   
    scanf("%d",&number_of_vertices);
 
    for(i=0;i<number_of_vertices;i++)
    {
        adjacency_list[i] = NULL;
       
        printf("Enter number of edges:");
        scanf("%d",&no_of_edges);

        for(i=0;i<no_of_edges;i++)
        {
            printf("Enter an edge(u,v):");
            scanf("%d%d",&vi,&vj);
            insert(vi,vj);
        }
    }
}
 
void insert(int vi,int vj)
{
    node *p,*q;
    
    q=(node*)malloc(sizeof(node));
    q->vertex = vj;
    q->next = NULL;

    if(adjacency_list[vi] == NULL)
        adjacency_list[vi] = q;
    else
    {
        p = adjacency_list[vi];  
        while(p->next != NULL)
            p = p->next;
        p->next = q;
    }
}

int main()
{
    read_graph();
    for(int i=0; i < number_of_vertices; i++)
        visited[i]=0;
    DFS(0);
    return 1;
}