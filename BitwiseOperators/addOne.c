#include <stdio.h>

unsigned addOne(unsigned x) {
  return - ~x;
}

int main() {
  printf("addOne(1) = %d \n", addOne(1));
  printf("addOne(2) = %d \n", addOne(2));
  printf("addOne(3) = %d \n", addOne(3));
  printf("addOne(4) = %d \n", addOne(4));
}