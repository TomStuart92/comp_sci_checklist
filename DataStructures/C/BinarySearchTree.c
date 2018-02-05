#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int key;
    struct node *parent;
    struct node *leftChild;
    struct node *rightChild;
};


struct node* newNode(int key);
struct node* insert(struct node* currentNode, int key);
struct node* search(struct node* currentNode, int key);
void print(struct node*);

struct node *newNode(int key) 
{
  struct node *newNode = (struct node*) malloc(sizeof(struct node));
  newNode->key = key;
  newNode->leftChild = newNode->rightChild = NULL;
  return newNode;
}

struct node* insert(struct node* currentNode, int key)
{
  // new BST, insert at head;
  if(currentNode == NULL) {
    return newNode(key);
  } 
  
  // recurse down correct tree
  if (key <= currentNode->key) {
    currentNode->leftChild = insert(currentNode->leftChild, key);
  } else {
    currentNode->rightChild = insert(currentNode->rightChild, key);
  }
  return currentNode; 
}

struct node* search(struct node* currentNode, int key)
{
  if(currentNode == NULL)
    return NULL;

  if(currentNode->key == key)
    return currentNode;
  else if(key < currentNode->key)  
    return search(currentNode->leftChild, key);
  else 
    return search(currentNode->rightChild, key);
}

void print(struct node* current) 
{
  if (current != NULL) {
    print(current->leftChild);
    printf("key: %d \n",current->key);  
    print(current->rightChild);
  }
}

int main() 
{
  struct node *root = NULL;
  root = insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 4);
  insert(root, 0);
  print(root);
  search(root, 3);
  return 0;
}