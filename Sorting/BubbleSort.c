#include <stdio.h>

void swap(int v[], int i, int j) {
  v[i] ^= v[j];
  v[j] ^= v[i];
  v[i] ^= v[j];
}


void bubbleSort(int v[], int size) 
{ 
  int end = size;
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < end; j++) {
      if(v[j] > v[j + 1])
        swap(v, j, j+1);
    }
    end -= 1;
  }
}

void printArray(int v[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d\n", v[i]);
}

int main() 
{
  int test[5] = { 3, 2, 1, 5, 4 };
  printf("Unsorted: \n");
  printArray(test, 5);  
  printf("Sorted: \n");
  bubbleSort(test, 5);
  printArray(test, 5);
}