#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef node
    #include "Node.h"

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    struct node* array;
};
 

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
 
void enqueue(struct Queue* queue, struct node* item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = *item;
    queue->size = queue->size + 1;
}
 
struct node dequeue(struct Queue* queue)
{
    struct node item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
struct node* front(struct Queue* queue)
{
    return &queue->array[queue->front];
}
 
#endif