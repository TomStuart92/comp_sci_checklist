#include <stdio.h>

void swap(int v[], int i, int j) {
  v[i] ^= v[j];
  v[j] ^= v[i];
  v[i] ^= v[j];
}

void printArray(int v[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d, ", v[i]);
  printf("\n");
}

void insertionSort(int v[], int size) 
{ 
  int key = 1;
  for(int i = 0; i < size; i++) {
    int position = key;
    while(position >= 1 && (v[position] < v[position - 1])) {
      swap(v, position, position -1);
      position -= 1;
    }
    key++;
  }
}



int main() 
{
  int test[5] = { 3, 2, 1, 5, 4 };
  printf("Unsorted: \n");
  printArray(test, 5);  
  printf("Sorted: \n");
  insertionSort(test, 5);
  printArray(test, 5);
}