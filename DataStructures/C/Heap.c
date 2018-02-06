#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAPSIZE 10

struct heap 
{
  int size;
  int count;
  int* array;
};
 
//helpers
void swap(int *a, int* b);
void printArray(int* array, int size);

//core heap API
struct heap* heapInit();
struct heap* insert(struct heap* heap, int value);
struct heap* siftUp(struct heap* heap, int index);
int getMax(struct heap* heap);
int getSize(struct heap* heap);
int isEmpty(struct heap* heap);
int extractMax(struct heap* heap);
void siftDown(struct heap* heap, int index);
int removeValue(struct heap* heap, int value);
int findIndex(struct heap* heap, int value);

//heap sort API
struct heap* heapify(int* array, int size);
void heapSort(int* array, int size);

//helpers
void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}

void printArray(int* array, int size)
{
  printf("\n[");
  for(int i = 0; i < size; i++)
    printf("%d, ", array[i]);
  printf("]\n");
}

//core heap API
struct heap* heapInit() {
  struct heap* heap = (struct heap*) malloc(sizeof(struct heap));
  heap->size = HEAPSIZE;
  heap->count = 0;
  heap->array = (int *) malloc(sizeof(int) * HEAPSIZE);
  return heap;
}

struct heap* insert(struct heap* heap, int value) 
{
  int leafIndex = heap->count++;
  heap->array[leafIndex] = value;
  return siftUp(heap, leafIndex);
}

struct heap* siftUp(struct heap* heap, int index)
{
  int parentIndex = (index - 1) / 2;

  // check if invariant is already satisfied.
  if(heap->array[parentIndex] >= heap->array[index]) return heap;

  // if not swap parent and child
  swap(&heap->array[parentIndex], &heap->array[index]);

  // recurse on parent index
  return siftUp(heap, parentIndex);
}

int getMax(struct heap* heap)
{
  return heap->array[0];
};

int getSize(struct heap* heap)
{
  return heap->count;
}

int isEmpty(struct heap* heap)
{
  return heap->count == 0 ? 1 : 0;
}

int extractMax(struct heap* heap)
{
  // swap maximum with last leaf node.
  int max = heap->array[0];
  int leafIndex = --heap->count;
  swap(&heap->array[0], &heap->array[leafIndex]);
  siftDown(heap, 0);
  return max;
}

void siftDown(struct heap* heap, int index)
{
  int largest = index;
  int leftIndex = (index << 1) + 1;    // leftIndex = 2k + 1;
  int rightIndex = (index + 1) << 1;    // rightIndex = 2k + 2;
  
  if(leftIndex < heap->size && heap->array[leftIndex] > heap->array[largest])
    largest = leftIndex;
  
  if(rightIndex < heap->size && heap->array[rightIndex] > heap->array[largest])
    largest = rightIndex;
  
  if(largest != index) 
  {
    swap(&heap->array[largest], &heap->array[index]);
    siftDown(heap, index);
  }
}

int removeValue(struct heap* heap, int value) 
{
  int valueIndex = findIndex(heap, value);
  int leafIndex = heap->count--;
  swap(&heap->array[valueIndex], &heap->array[leafIndex]);
  siftDown(heap, valueIndex);
  return value;
}

int findIndex(struct heap* heap, int value)
{
  for(int i = 0; i < heap->count; i++)
    if(heap->array[i] == value)
      return i;
  return -1;
}

//heap sort API
struct heap* heapify(int* array, int size) 
{
  struct heap* heap = (struct heap*) malloc(sizeof(struct heap));
  heap->size = size;
  heap->array = array;

  for(int i = (heap->size - 2 ) / 2; i >= 0; --i)
    siftDown(heap, i);
  return heap;
}

void heapSort(int* array, int size)
{
  struct heap* heap = heapify(array, size);
  while(heap->size > 1)
  {
    //swap largest element at root with last leaf;
    swap(&heap->array[0], &heap->array[heap->size - 1]);
    //decrement size;
    --heap->size;
    // bubble down new root node;
    siftDown(heap, 0);
  }
}

int main()
{
  struct heap* heap = heapInit();
  insert(heap, 4);
  insert(heap, 5);
  insert(heap, 1);
  insert(heap, 2);
  insert(heap, 3);
  insert(heap, 6);
  printf("Max Value: %d \n", getMax(heap));
  printf("Heap Size: %d \n", getSize(heap));
  printf("Heap is empty: %d \n", isEmpty(heap));
  printf("Remove max: %d\n", extractMax(heap));
  printf("New Max Value: %d \n", getMax(heap));
  printf("Remove value 3: %d\n", removeValue(heap, 3));
  printf("Heap Size: %d \n", getSize(heap));
}
