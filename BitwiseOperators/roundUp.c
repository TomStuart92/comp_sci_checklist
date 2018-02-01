#include <stdio.h>

unsigned int roundUpToNextPowerOfTwo(unsigned int x)
{
  x--;
  x |= x >> 1;  // handle  2 bit numbers
  x |= x >> 2;  // handle  4 bit numbers
  x |= x >> 4;  // handle  8 bit numbers
  x |= x >> 8;  // handle 16 bit numbers
  x |= x >> 16; // handle 32 bit numbers
  x++;
  return x;
}

int main() 
{
  printf("round up 1 = %d \n", roundUpToNextPowerOfTwo(1));
  printf("round up 2 = %d \n", roundUpToNextPowerOfTwo(2));
  printf("round up 3 = %d \n", roundUpToNextPowerOfTwo(3));
}