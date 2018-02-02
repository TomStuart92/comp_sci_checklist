#include <stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for(int j = low; j <= high - 1; j++)
  {
    if (arr[j] <= pivot) 
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i+1], &arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(int v[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d, ", v[i]);
  printf("\n");
}

int main() 
{
  int test[5] = { 3, 2, 1, 5, 4 };
  printf("Unsorted: \n");
  printArray(test, 5);  
  printf("Sorted: \n");
  quickSort(test, 0, 4);
  printArray(test, 5);
}