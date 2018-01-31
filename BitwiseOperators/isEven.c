#include <stdio.h>

unsigned isEven(unsigned x) 
{
  return (x & 1) == 0;
}

int main() {
  printf("isEven(1) = %d \n", isEven(1));
  printf("isEven(2) = %d \n", isEven(2));
  printf("isEven(3) = %d \n", isEven(3));
  printf("isEven(4) = %d \n", isEven(4));
}