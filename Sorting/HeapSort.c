#include <stdio.h>
#include <stdlib.h>

struct heap 
{
  int size;
  int* array;
};

void swap(int *a, int* b);
void heapify(struct heap* heap, int index);
struct heap* createHeap(int* array, int size);
void heapSort(int* array, int size);
void printArray(int* array, int size);

void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}

void heapify(struct heap* heap, int index)
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
    heapify(heap, index);
  }
}

struct heap* createHeap(int* array, int size) 
{
  struct heap* heap = (struct heap*) malloc(sizeof(struct heap));
  heap->size = size;
  heap->array = array;

  for(int i = (heap->size - 2 ) / 2; i >= 0; --i)
    heapify(heap, i);
  return heap;
}

void heapSort(int* array, int size)
{
  struct heap* heap = createHeap(array, size);
  while(heap->size > 1)
  {
    //swap largest element at root with last leaf;
    swap(&heap->array[0], &heap->array[heap->size - 1]);
    //decrement size;
    --heap->size;
    // bubble down new root node;
    heapify(heap, 0);
  }
}

void printArray(int* array, int size)
{
  for(int i = 0; i < size; i++)
    printf("%d ", array[i]);
}

int main()
{
  int array[] = {12, 11, 13, 5, 6, 7};
  int size = sizeof(array) / sizeof(array[0]);
  printf("\nBefore Sort: \n");
  printArray(array, size);
  printf("\nAfter Sort: \n");
  heapSort(array, size);
  printArray(array, size);
  return 0;
}
