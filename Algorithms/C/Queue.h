#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node 
{
    int key;
    struct node* parent;
    struct node* leftChild;
    struct node* rightChild;
};

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    struct node* array;
};

struct node* newNode(int key) 
{
  struct node *newNode = (struct node*) malloc(sizeof(struct node));
  newNode->key = key;
  newNode->leftChild = newNode->rightChild = NULL;
  return newNode;
}
 
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1;  // This is important, see the enqueue
    queue->array = (struct node*) malloc(queue->capacity * sizeof(struct node *));
    return queue;
}
 
int isFull(struct Queue* queue)
{  
  return (queue->size == queue->capacity);  
}
 
int isEmpty(struct Queue* queue)
{  
  return (queue->size == 0); 
}
 
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    struct node* node = newNode(item);
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = *node;
    queue->size = queue->size + 1;
}
 
int dequeue(struct Queue* queue)
{
    struct node item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item.key;
}
 
struct node* front(struct Queue* queue)
{
    return &queue->array[queue->front];
}
