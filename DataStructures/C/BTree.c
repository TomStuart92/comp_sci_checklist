#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define EMPTY 0
#define NODE_ORDER 3
#define NODE_POINTERS (NODE_ORDER * 2)
#define NODE_KEYS (NODE_POINTERS - 1)

typedef unsigned char bool;

typedef struct Node {
  int keys[NODE_KEYS];
  struct Node* children[NODE_POINTERS];
  unsigned int keyIndex;
  bool leaf;
} Node; 

typedef struct Result {
  Node* nodePointer;
  int key;
  bool found;
  unsigned int depth;
} Result;

typedef struct BTree {
  Node *root;
  unsigned short order;
  bool lock;
} BTree;

static int BTreeGetLeftMax(Node* T);
static int BTreeGetRightMin(Node* T); 
Node* createNode(); 
BTree* createBTree();
Result* createResultSet();
void print_node(Node* n);
Result* search(int key, Node* root);
static void split_child(Node* parent, Node* children, int i);
static void insert_nonfull(Node* n, int key);
Node* insert(int key, BTree* b);
static void merge_children(Node* root, int index, Node* child1, Node* child2);
static void BTreeBorrowFromLeft(Node* root, int index, Node* leftPtr, Node* currentPtr);
static void BTreeBorrowFromRight(Node* root, int index, Node* rightPtr, Node* currentPtr);
static void BTreeDeleteNoNone(int X, Node* root);
Node* delete(int key, BTree* b);
void tree_unlock(BTree* b);
bool tree_lock(BTree* b);

Node* createNode() 
{
  Node* newNode = (Node*) malloc(sizeof(Node));
  if (!newNode) {
    printf("Out of memory");
    exit(0);
  }

  for(int i = 0; i < NODE_KEYS; i++)
    newNode->keys[i] = 0;

  for(int j = 0; j < NODE_POINTERS; j++)
    newNode->children[j] = NULL;

  newNode->keyIndex = EMPTY;
  newNode->leaf = TRUE;

  return newNode;
}

BTree* createBTree()
{
  BTree* newRoot = (BTree *) malloc(sizeof(BTree));
    if (!newRoot) {
      printf("Out of memory");
      exit(0);
    }

  Node* head = createNode();
  newRoot->order = NODE_ORDER;
  newRoot->root = head;
  newRoot->lock = FALSE;

  return newRoot;
}

Result* createResultSet()
{
  Result* newResult = (Result*) malloc(sizeof(Result));
  if (!newResult) {
    printf("Out of memory");
    exit(0);
  }

  newResult->nodePointer = NULL;
  newResult->key = 0;
  newResult->found = FALSE;
  newResult->depth = 0;
  return newResult;
}

void print_node(Node* n) 
{
	printf(">>-----0x%x-----\n", n);
	printf("  Index: %d\n", n->keyIndex);

	printf("   Leaf: ");
	n->leaf ? printf("TRUE\n") : printf("FALSE\n");

	printf("  Array:");
	for(int i = 0; i < n->keyIndex; i++){
		printf(" [%d : %d]", i, n->keys[i]);
	}

	printf("\n  Child:");
	if(n->leaf){
		printf(" NONE");
	}else{
		for(int q = 0; q < NODE_POINTERS; q++){
			printf(" [%d : %x]", q, n->children[q]);
		}
	}
	printf("\n<<------------------\n");
}

Result* search(int key, Node* root)
{
  print_node(root);
  int i = 0;
  while((i < root->keyIndex) && (key > root->keys[i]))
    i++;

  // if we find a result
  if((i <= root->keyIndex) && (key == root->keys[i])) 
  {
    Result* result = createResultSet();
    result->nodePointer = root;
    result->key = i;
    result->found = TRUE;
    return result;
  }
  // if root is leaf, no tree left to search. 
  if(root->leaf) {
    Result* result = createResultSet();
    result->nodePointer = root;
    result->found = FALSE;
    return result;
  } else {
    return search(key, root->children[i]); 
  }
}

static void split_child(Node* parent, Node* children, int i)
{
  Node* newNode = createNode();
  newNode->leaf = children->leaf;
  newNode->keyIndex = NODE_ORDER - 1;

  for(int j = 0; j< NODE_ORDER - 1; j++)
    newNode->keys[j] = children->keys[NODE_ORDER+j];

  if(children->leaf == 0)
    for(int k = 0; k < NODE_ORDER; k++) {
      newNode->children[k] = children->children[NODE_ORDER+k];
    }
  
  children->keyIndex = NODE_ORDER - 1;

  for(int m = parent->keyIndex; m >= i; m--)
    parent->children[m+1] = parent->children[m];

  parent->children[i] = newNode;

  for(int l = parent->keyIndex; l >= i; l--)
    parent->keys[l] = parent->keys[l-1];

  parent->keys[i-1] = children->keys[NODE_ORDER - 1];
  parent->keyIndex++; 
}

static void insert_nonfull(Node* n, int key)
{
  int i = n->keyIndex;
  
  if(n->leaf) //shift keys to make space
  {
    while(i>=1 && key < n->keys[i-1]) 
    {
      n->keys[i] = n->keys[i - 1];
      i--;
    }
    n->keys[i] = key;
    n->keyIndex++;
  }
  else 
  {
    while(i>=1 && key<n->keys[i - 1])
      i--;
    if(n->children[i]->keyIndex == NODE_KEYS)
    {
      split_child(n, i+1, n->children[i]);
      if (key > n->keys[i])
        i++;
    }
    insert_nonfull(n->children[i], key);
  }
}

Node* insert(int key, BTree* b)
{
  Node* root = b->root;

  if(b->lock) 
  {
    printf("Tree is locked\n");
    return root;
  }

  Node* newNode = createNode();
  newNode->leaf = FALSE;
  newNode->keyIndex = 0;
  newNode->children[0] = root;

  if(root->keyIndex == NODE_KEYS)  // node is full, split
  {
    b->root = newNode;
    split_child(newNode, 1, root);
  }
  insert_nonfull(newNode, key);
  return b->root;
}

static void merge_children(Node* root, int index, Node* child1, Node* child2)
{
  child1->keyIndex = NODE_KEYS;

  for(int i = NODE_ORDER; i < NODE_KEYS; i++)
    child1->keys[i] = child2->keys[i-NODE_ORDER];
  child1->keys[NODE_ORDER - 1] = root->keys[index];

  if(child2->leaf == FALSE) 
  {
    for(int i = NODE_ORDER; i < NODE_POINTERS; i++)
      child1->children[i] = child2->children[i - NODE_ORDER];
  }

  for(int i = index + 1; i < root->keyIndex; i++)
  {
    root->keys[i-1] = root->keys[i];
    root->children[i] = root->children[i+1];
  }
  root->keyIndex--;
  free(child2);
}

static void BTreeBorrowFromLeft(Node* root, int index, Node* leftPtr, Node* currentPtr)
{
  currentPtr->keyIndex++;
  for(int i = currentPtr->keyIndex-1; i > 0; i--)
    currentPtr->keys[i] = currentPtr->keys[i - 1];
  currentPtr->keys[0] = root->keys[index];
  root->keys[index] = leftPtr->keys[leftPtr->keyIndex-1];
  if(leftPtr->leaf == FALSE)
    for(int i = currentPtr->keyIndex; i > 0; i--)
      currentPtr->children[i] = currentPtr->children[i-1];
  currentPtr->children[0] = leftPtr->children[leftPtr->keyIndex];
  leftPtr->keyIndex--;
}

static void BTreeBorrowFromRight(Node* root, int index, Node* rightPtr, Node* currentPtr)
{
  currentPtr->keyIndex++;
	currentPtr->keys[currentPtr->keyIndex-1] = root->keys[index];
	root->keys[index] = rightPtr->keys[0];
	int i;
	for(i=0;i<rightPtr->keyIndex-1;i++)
		rightPtr->keys[i] = rightPtr->keys[i+1];
	if(0 == rightPtr->leaf){
		currentPtr->children[currentPtr->keyIndex] = rightPtr->children[0];
		for(i=0;i<rightPtr->keyIndex;i++)
			rightPtr->children[i] = rightPtr->children[i+1];
	}
	rightPtr->keyIndex--;
}

static void BTreeDeleteNoNone(int X, Node* root)
{
  int i;
  if(root->leaf == TRUE)
  {
    i = 0;
    while( (i< root->keyIndex) && (X > root->keys[i]))
      i++;
    if(X == root->keys[i]) 
    {
      for(; i < root->keyIndex-1; i++)
        root->keys[i] = root->keys[i+1];
      root->keyIndex--;
    }
    else 
    {
      printf("Node not found\n");
      return;
    }
  }
  else 
  {
    i = 0;
    Node* prePtr = NULL;
    Node* nextPtr = NULL;

    while( (i < root->keyIndex) && (X > root->keys[i]))
      i++;
    
    if( (i < root->keyIndex) && (X == root->keys[i]))
    {
      prePtr = root->children[i];
      nextPtr = root->children[i + 1];

      if(prePtr->keyIndex > NODE_ORDER - 1)
      {
        int aPrecursor = BTreeGetLeftMax(prePtr);
        root->keys[i] = aPrecursor;
        BTreeDeleteNoNone(aPrecursor, prePtr);
      }
      else
      {
        if(nextPtr->keyIndex > NODE_ORDER - 1) 
        {
          int aSuccessor = BTreeGetRightMin(nextPtr);
          root->keys[i] = aSuccessor;
          BTreeDeleteNoNone(aSuccessor, nextPtr);
        }
        else 
        {
          merge_children(root, i, prePtr, nextPtr);
          BTreeDeleteNoNone(X, prePtr);
        } 
      }
    }
    else 
    {
      prePtr = root->children[i];
      Node* leftBro = NULL;
      if(i < root->keyIndex)
        nextPtr = root->children[i+1];
      if(i > 0)
        leftBro = root->children[i-1];

      if(NODE_ORDER-1 == prePtr->keyIndex) 
      {
        if( (leftBro != NULL) && (leftBro->keyIndex >NODE_ORDER - 1))
          BTreeBorrowFromLeft(root, i-1, leftBro, prePtr);
        else
        {
          if( (nextPtr != NULL) && (nextPtr->keyIndex > NODE_ORDER - 1))
            BTreeBorrowFromRight(root, i, nextPtr, prePtr);
          else if (leftBro != NULL) 
          {
            merge_children(root, i-1, leftBro, prePtr);
            prePtr = leftBro;
          }
          else 
            merge_children(root, i, prePtr, nextPtr);
        }
        BTreeDeleteNoNone(X, prePtr);
      }
    }
  }
}

static int BTreeGetLeftMax(Node* T) 
{
  if(T->leaf == FALSE)
    return BTreeGetLeftMax(T->children[T->keyIndex]);
  else 
    return T->keys[T->keyIndex - 1];
}

static int BTreeGetRightMin(Node* T) 
{
  if(T->leaf == FALSE)
    return BTreeGetRightMin(T->children[T->keyIndex]);
  else 
    return T->keys[0];
}

Node* delete(int key, BTree* b) 
{
  if(!b->lock) 
  {
    if(b->root->keyIndex == 1) 
    {
      Node* child1 = b->root->children[0];
      Node* child2 = b->root->children[1];
      if((!child1) && (!child2)) 
      {
        if((NODE_ORDER-1 == child1->keyIndex) && (NODE_ORDER-1 == child2->keyIndex)) 
        {
          merge_children(b->root, 0, child1, child2);
          free(b->root);
          BTreeDeleteNoNone(key, child1);
          return child1;
        }
      }
    }
    BTreeDeleteNoNone(key, b->root);
  }
  else 
  {
    printf("Tree is locked\n");
  }
  return b->root;
}

void tree_unlock(BTree* b)
{
	b->lock = FALSE;
}

bool tree_lock(BTree* b)
{
	if(b->lock){
		return FALSE;
	}	
	b->lock = TRUE;
	return TRUE;
}

//---------------------------------TEST APP ------------------------------------------

void console(BTree *b)
{
	int number;
	char name[256];

	printf("BTree> ");
	scanf("%s", name);
	
	if(!strcmp("add", name)){
		scanf("%d", &number);
		if(number){
			b->root = insert(number, b);
		}
		printf("Insert %d\n", number);
	}else if(!strcmp("del", name)){
		scanf("%d", &number);
		if(number){
			b->root = delete(number, b);
		}
		printf("Delete %d\n", number);
	}else if(!strcmp("search", name)){
		scanf("%d", &number);
		if(number){
			Result *rs = search(number, b->root);
			if(rs->found){
				printf("Found\n");
				print_node(rs->nodePointer);
			}else{
				printf("Not found\n");
			}
		}
	}else if(!strcmp("tree", name)){
		printf("  Order: %d\n", b->order);
		printf("   Lock: ", b->lock);
		if(b->lock){
			printf("TRUE\n");
		}else{
			printf("FALSE\n");
		}
		print_node(b->root);
	}else if(!strcmp("lock", name)){
		tree_lock(b);
	}else if(!strcmp("unlock", name)){
		tree_unlock(b);
	}else if(!strcmp("exit", name)){
		exit(0);
	}else if(!strcmp("quit", name)){
		exit(0);
	}else{
		printf("Unknown [%s]\n", name);
	}

	return;
}

int main(int argc, char *argv[])
{
	int test[] = {1, -11, 12, 13, 15, 16, 17, 18, 19, 20, 25, 28, 29, 31,
				 35, 36, 39, 41, 42, 45, 55, 58, 59, 61, 67, 71, 73, 74,
				 76, 80, 81, 82, 83, 88, 89, 99, 83, 91, 93, 94, 95, 98};
	int test2[] = {-23, -234, -24, -3, -38, -82, -49, -72, -84, -27, -22,
				   -35, -9, -29, -374, -84, -24 , -92, -83, -372, -756};
	int todelete[] = {15, 19};

	BTree *main = createBTree();
	int i;

	for(i=0; i<sizeof(test)/sizeof(int); i++){
		main->root = insert(test[i], main);
	}

	for(i=0; i<sizeof(test2)/sizeof(int); i++){
		main->root = insert(test2[i], main);
	}

	for(i=0; i<sizeof(todelete)/sizeof(int); i++){
		main->root = delete(todelete[i], main);
	}

	// Run console for easy testing
	for(;;){
		console(main);
	}

	return 0;
}