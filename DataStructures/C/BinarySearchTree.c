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
int min(struct node* currentNode);
int max(struct node* currentNode);
int height(struct node* currentNode);

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

int min(struct node* currentNode) 
{
  if(currentNode->leftChild != NULL)
    return min(currentNode->leftChild);
  return currentNode->key;
}
int max(struct node* currentNode) 
{
  if(currentNode->rightChild != NULL)
    return max(currentNode->rightChild);
  return currentNode->key;
}

int height(struct node* currentNode) 
{
  if(currentNode == NULL)
    return 0;
  int leftHeight = height(currentNode->leftChild);
  int rightHeight = height(currentNode->rightChild);
  return rightHeight > leftHeight ? rightHeight + 1 : leftHeight + 1;
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
  printf("looking for value 3 = %d \n", search(root, 3)->key);
  printf("min value: %d \n", min(root));
  printf("max value: %d \n", max(root));
  printf("height: %d \n", height(root));
  return 0;
}