#include <stdio.h>

unsigned isPowerOfTwo(unsigned x) {
  return (x & x-1) == 0;
}

int main() {
  printf("isPowerOfTwo(1) = %d \n", isPowerOfTwo(1));
  printf("isPowerOfTwo(2) = %d \n", isPowerOfTwo(2));
  printf("isPowerOfTwo(3) = %d \n", isPowerOfTwo(3));
  printf("isPowerOfTwo(4) = %d \n", isPowerOfTwo(4));
}