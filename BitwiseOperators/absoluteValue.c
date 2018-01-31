#include <stdio.h>

int myAbs(int x)
{
  const int bit31 = x >> 31;
  return (x ^ bit31) - bit31;
}

int main() {
  printf("myAbs(1) = %d \n", myAbs(1));
  printf("myAbs(-2) = %d \n", myAbs(-2));
  printf("myAbs(3) = %d \n", myAbs(3));
  printf("myAbs(-4) = %d \n", myAbs(-4));
}