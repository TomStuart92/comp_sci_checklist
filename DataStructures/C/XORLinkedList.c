#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// An XOR linked list is a more memory efficient doubly linked list. 
// Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. 
// Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.

typedef struct node {
    int data;
    struct node *both;
} node;

node* head;          // head pointer holds the address of the first node
node* tail;          // tail pointer holds the address of the last node

node* xor(node* a, node* b)
{
  return (node*) ((uintptr_t) a ^ (uintptr_t) b);
}

void add(int data)
{
  node* newNode = (node*) malloc(sizeof(node));
  newNode->data = data;

  if(NULL == head) {
    newNode->both = NULL;
    head = tail = newNode;
  } else {
    // xor null and previous tail;
    newNode->both = xor(tail, NULL);
    // find current penultimate node;
    node* previousPenultimate = xor(tail->both, NULL);
    // update current tail node;
    tail->both = xor(newNode, previousPenultimate);
    tail = newNode;
  }
}

void get(int index)
{
  node* current = head;
  node* previous = NULL;
  node* next;
  for(int i = 0; i < index; i++) {
    next = xor(previous, current->both);
    previous = current;
    current = next;
  }
  printf("Node at %d: %d\n", index, current->data);
}


void list() {
  node* current = head;
  node* previous = NULL;
  node* next;
  
  printf("Current Content\n");
  while(NULL != current) {
    printf("%d\n", current->data);
    next = xor(previous, current->both);
    previous = current;
    current = next;
  }
}


int main()
{
    head = NULL;
    tail = NULL;
    add(1);
    add(2);
    add(3);
    list();
    get(0);
    get(1);
    get(2);
}


