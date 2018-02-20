#include <stdio.h>
#include <stdlib.h>

struct Node {
  int key;
  struct Node *left;
  struct Node *right;
};

struct Node* newNode(int key);
struct Node* rightRotate(struct Node* x);
struct Node* leftRotate(struct Node* x);
struct Node* splay(struct Node* root, int key);
struct Node* insert(struct Node* root, int k);
void preOrder(struct Node* root);
struct Node* deleteNode(struct Node* root, int key); 

struct Node* newNode(int key) 
{
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct Node* rightRotate(struct Node* x) 
{
  struct Node* y = x->left;
  x->left = y->right;
  y->right = x;
  return y;
}

struct Node* leftRotate(struct Node* x)
{
  struct Node* y = x->right;
  x->right = y->left;
  y->left = x;
  return y;
}

struct Node* splay(struct Node* root, int key)
{ 
  if (root == NULL || root->key == key)
    return root;

  if (root->key > key)      // key in left subtree
  {
    if (root->left == NULL) return root;       // key is not in tree. return root.

    if(root->left->key > key) // left-left splay
    {
      root->left->left = splay(root->left->left, key);
      root = rightRotate(root);
    } 
    else if (root->left->key < key ) // left-right splay
    {
      root->left->right = splay(root->left->right, key);
      if (root->left->right != NULL)
        root->left = leftRotate(root->left);
    }

    return (root->left == NULL) ? root : rightRotate(root);
  }
  else    //key in right subtree
  {
    if (root->right == NULL) return root;      // key is not in tree. return root.

    if(root->right->key > key)      //right-left splay
    {
      root->right->left = splay(root->right->left, key);
      if (root->right->left != NULL)
        root->right = rightRotate(root->right);
    } 
    else if (root->right->key < key) // right-right splay
    {
      root->right->right = splay(root->right->right, key);
      root = leftRotate(root);
    }
    return (root->right == NULL) ? root : leftRotate(root);
  }
}

struct Node* insert(struct Node *root, int k)
{
  if (root == NULL) return newNode(k);

  root = splay(root, k);

  if(root->key == k) return root;

  struct Node* newnode = newNode(k);
  if (root->key > k)
  {
    newnode->right = root;
    newnode->left = root->left;
    root->left = NULL;
  } 
  else 
  {
    newnode->left = root;
    newnode->right = root->right;
    root->right = NULL;
  }
  return newnode;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct Node* deleteNode(struct Node* root, int key) 
{
  if(!root) return NULL;

  struct Node* temp;
  root = splay(root, key);

  if (key != root->key) return root;

  if (!root->left)
  {
    temp = root;
    root = root->right;
  }
  else 
  {
    temp = root;
    root = splay(root->left, key);
    root->right = temp->right;
  }

  free(temp);
  return root;
}


int main()
{
    struct Node *root = newNode(100);
    root->left = newNode(50);
    root->right = newNode(200);
    root->left->left = newNode(40);
    root->left->left->left = newNode(30);
    root->left->left->left->left = newNode(20);
    root = insert(root, 25);
    root = deleteNode(root, 40);
    printf("Preorder traversal of the modified Splay tree is \n");
    preOrder(root);
    return 0;
}

