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

void BFS(int i)
{
    int number_visited = 0;
    int queue_head = -1;
    node* queue[MAX_VERTICES];
    
    queue[++queue_head] = adjacency_list[i];
    visited[i] = 1;

    while(number_visited <= queue_head ) {
        node* p = queue[queue_head];
        while(p != NULL) {
            p = p->next;
            if (!visited[p->vertex]) {
                printf("\n%d\n", p->vertex);
                number_visited++;
                visited[p->vertex] = 1;
                queue[++queue_head] = p;
            }
        }
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
    BFS(0);
    return 1;
}