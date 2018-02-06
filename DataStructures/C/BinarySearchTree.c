#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct node* newNode(int key);
struct node* insert(struct node* currentNode, int key);
struct node* search(struct node* currentNode, int key);
void print(struct node*);
int min(struct node* currentNode);
struct node* findMin(struct node* currentNode);
int max(struct node* currentNode);
int height(struct node* currentNode);
void DFS(struct node* currentNode);
void BFS(struct node* currentNode);
int isBST(struct node* currentNode);
struct node* delete(struct node* currentNode, int key);
struct node* successor(struct node* currentNode, int key);

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

void print(struct node* currentNode) 
{
  if (currentNode != NULL) {
    print(currentNode->leftChild);
    printf("key: %d \n",currentNode->key);  
    print(currentNode->rightChild);
  }
}

int min(struct node* currentNode) 
{
  if(currentNode->leftChild != NULL)
    return min(currentNode->leftChild);
  return currentNode->key;
}

struct node* findMin(struct node* currentNode) 
{
  if(currentNode->leftChild != NULL)
    return findMin(currentNode->leftChild);
  return currentNode;
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

void BFS(struct node* currentNode)
{
  if(currentNode == NULL) return;
  struct Queue* queue = createQueue(1000);
  enqueue(queue, currentNode);
  while(!isEmpty(queue)) {
    struct node* current = front(queue);
    printf("key: %d \n", current->key);
    if(current->leftChild != NULL) enqueue(queue, current->leftChild);
    if(current->rightChild != NULL) enqueue(queue, current->rightChild);
    dequeue(queue);
  }
}

void DFS(struct node* currentNode)
{
  // preorder traversal
  if(currentNode == NULL)
    return;
  printf("key: %d \n",currentNode->key);
  DFS(currentNode->leftChild);
  DFS(currentNode->rightChild);
}

int isBST(struct node* currentNode)
{
  if(currentNode == NULL) {
    return 0;
  }
  if(currentNode->leftChild != NULL && currentNode->key < currentNode->leftChild->key) {
    return 1;
  }
  if(currentNode->rightChild != NULL && currentNode->key > currentNode->rightChild->key) {
    return 1;
  }
  return isBST(currentNode->leftChild) + isBST(currentNode->rightChild);
}

struct node* delete(struct node* currentNode, int key)
{
  if(currentNode == NULL) return currentNode;
  else if (key < currentNode->key) currentNode->leftChild = delete(currentNode->leftChild, key);
  else if (key > currentNode->key) currentNode->rightChild = delete(currentNode->rightChild, key);
  else {
    //case 1: no child
    if (currentNode->leftChild == NULL && currentNode->rightChild == NULL) {
      free(currentNode);
      currentNode = NULL;
    }

    //case 2: 1 child
    else if (currentNode->leftChild == NULL) {
      struct node* temp = currentNode;
      currentNode = currentNode->rightChild;
      free(currentNode);
    }

    else if (currentNode->rightChild == NULL) {
      struct node* temp = currentNode;
      currentNode = currentNode->leftChild;
      free(currentNode);
    }

    //case 3: 2 children
    else {
      struct node* temp = findMin(currentNode->rightChild);
      currentNode->key = temp->key;
      currentNode->rightChild = delete(currentNode->rightChild, temp->key);
    }
  }
  return currentNode; 
}

struct node* successor(struct node* currentNode, int key)
{
  struct node* targetNode = search(currentNode, key);
  if (targetNode == NULL) return NULL;

  // case 1: target has right child.
  if (targetNode->rightChild != NULL) return findMin(targetNode->rightChild);

  // case 2: no right subtree.
  else {
    struct node* successor = NULL;
    struct node* ancestor = currentNode;
    while(ancestor != currentNode) {
      if(currentNode->key < ancestor->key) {
        successor = ancestor;
        ancestor = ancestor->leftChild;
      } else 
        ancestor = ancestor->rightChild;
    }
    return successor;
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
  printf("looking for value 3 = %d \n", search(root, 3)->key);
  printf("min value: %d \n", min(root));
  printf("max value: %d \n", max(root));
  printf("height: %d \n", height(root));
  printf("Breadth First Search \n");
  BFS(root);
  printf("Depth First Search \n");
  DFS(root);
  printf("isbst: %d \n", isBST(root));
  delete(root, 3);
  printf("successor to 2: %d \n", successor(root, 2)->key);
  return 0;
}