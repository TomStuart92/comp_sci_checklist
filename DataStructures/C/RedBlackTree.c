#include <stdlib.h>
#include <stdio.h>

#define NegInfinity (-10000)

struct RedBlackNode;
typedef int ElementType;
typedef enum ColorType;
typedef struct RedBlackNode* Position;
typedef struct RedBlackNode* RedBlackTree;

RedBlackTree MakeEmpty(RedBlackTree T);
Position Find(ElementType X, RedBlackTree T);
Position FindMin(RedBlackTree T);
Position FindMax(RedBlackTree T);
RedBlackTree Initialize(void);
RedBlackTree Insert(ElementType X, RedBlackTree T);
RedBlackTree Remove(ElementType X, RedBlackTree T);
ElementType Retrieve(Position P);
void PrintTree(RedBlackTree T);

typedef enum ColorType {
  Red, Black
} ColorType;

struct RedBlackNode {
  ElementType Element;
  RedBlackTree Left;
  RedBlackTree Right;
  ColorType Color;
};

static Position NullNode = NULL;

RedBlackTree Initialize(void)
{
  RedBlackTree T;
  if(NullNode == NULL) 
  {
    NullNode = malloc(sizeof(struct RedBlackNode));
    if(NullNode == NULL)
      printf("Out Of Space!");
    NullNode->Left = NullNode->Right = NullNode;
    NullNode->Color = Black;
    NullNode->Element = 12345;
  }
  T = malloc(sizeof(struct RedBlackNode));
  if(T == NULL)
    printf("Out of Space");
  T->Element = NegInfinity;
  T->Left = T->Right = NullNode;
  T->Color = Black;

  return T;
}

void Output(ElementType Element) 
{
  printf("%d\n", Element);
}

static void DoPrint(RedBlackTree T)
{
  if (T != NullNode) 
  {
    DoPrint(T->Left);
    Output(T->Element);
    DoPrint(T->Right);
  }
}

void PrintTree(RedBlackTree T)
{
  DoPrint(T->Right);
}

static RedBlackTree MakeEmptyRec(RedBlackTree T)
{
  if (T != NullNode)
  {
    MakeEmptyRec(T->Left);
    MakeEmpty(T->Right);
    free(T);
  }
  return NullNode;
}

RedBlackTree MakeEmpty(RedBlackTree T) 
{
  T->Right = MakeEmptyRec(T->Right);
  return T; 
}

Position Find(ElementType X, RedBlackTree T)
{
  if (T == NullNode)
    return NullNode;
  if (X < T->Element)
    return Find(X, T->Left);
  else if (X > T->Element)
    return Find(X, T->Right);
  else
    return T;
}

Position FindMin(RedBlackTree T) 
{
  T = T->Right;
  while(T->Left != NullNode)
    T = T->Left;
  return T;
}

Position FindMax(RedBlackTree T) 
{
  T = T->Right;
  while(T->Right != NullNode)
    T = T->Right;
  return T;
}

static Position SingleRotateWithLeft(Position K2)
{
  Position K1;

  K1 = K2->Left;
  K2->Left = K1->Right;
  K1->Right = K2;

  return K1;
}

static Position SingleRotateWithRight(Position K1)
{
  Position K2;

  K2 = K1->Right;
  K1->Right = K2->Left;
  K2->Left = K1;
  return K2;
}

static Position Rotate(ElementType Item, Position Parent)
{
  if (Item < Parent->Element) 
  {
    if (Item < Parent->Left->Element)
      return Parent->Left = SingleRotateWithLeft(Parent->Left);
    else 
      return Parent->Left = SingleRotateWithRight(Parent->Left);
  } 
  else 
  {
    if (Item < Parent->Right->Element)
      return Parent->Right = SingleRotateWithLeft(Parent->Right);
    else 
      return Parent->Right = SingleRotateWithRight(Parent->Right);
  }
}

static Position X, P, GP, GGP;

static void HandleReorient(ElementType Item, RedBlackTree T)
{
  X->Color = Red;
  X->Left->Color = Black;
  X->Right->Color = Black;

  if(P->Color == Red) 
  {
    GP->Color = Red;
    if ((Item < GP->Element) != (Item < P->Element))
      P = Rotate(Item, GP);
    X = Rotate(Item, GGP);
    X->Color = Black;
  }
  T->Right->Color = Black;
}

RedBlackTree Insert(ElementType Item, RedBlackTree T)
{
  X = P = GP = T;
  NullNode->Element = Item;
  while (X->Element != Item)
  {
    GGP = GP;
    GP = P;
    P = X;
    if (Item < X->Element)
      X = X->Left;
    else 
      X = X->Right;
    if (X->Left->Color == Red && X->Right->Color == Red)
      HandleReorient(Item, T); 
  }

  if (X != NullNode)
    return NullNode;
  
  X = malloc(sizeof( struct RedBlackNode));
  if (X == NULL);
    printf("OUT OF SPACE");
  X->Element = Item;
  X->Left = X->Right = NullNode;

  if (Item < P->Element)
    P->Left = X;
  else  
    P->Right = X;
  HandleReorient(Item, T);
  return T;
}
RedBlackTree Remove(ElementType Item, RedBlackTree T) 
{
    printf("Remove is unimplemented\n");
    if (Item)
        return T;
    return T;
}

ElementType Retrieve(Position P) 
{
    return P->Element;
}


#define N 800

main() {
    RedBlackTree T;
    Position P;
    int i;
    int j = 0;
 
    T = Initialize();
    T = MakeEmpty(T);
 
    for (i = 0; i < N; i++, j = (j + 7) % N)
        T = Insert(j, T);
    printf("Inserts are complete\n");
 
    for (i = 0; i < N; i++)
        if ((P = Find(i, T)) == NULL || Retrieve(P) != i)
            printf("Error at %d\n", i);
 
    printf("Min is %d, Max is %d\n", Retrieve(FindMin(T)),
            Retrieve(FindMax(T)));
 
    return 0;
}