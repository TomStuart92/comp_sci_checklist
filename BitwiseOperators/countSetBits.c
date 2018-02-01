#include <stdio.h>

unsigned int kernighanCount(unsigned int v) 
{
  unsigned int c; // c accumulates the total bits set in v
  for (c = 0; v; c++) {
    v &= v - 1; // clear the least significant bit set
  }
  return c;
}

unsigned int maskCount(unsigned int v) 
{
  unsigned int mask = 0b1000000;
  unsigned int count = 0;
  for (int i = 0; i < 8; i++) {
    if ((v & mask) != 0) {
      count++;
    }
    mask = mask >> 1;
  }
  return count;
}

unsigned int builtInCount(unsigned int v) 
{
  return __builtin_popcount(v);
}

unsigned int populationCount(unsigned int x) 
{
    x -= ((x >> 1) & 0x55555555);
    x = (((x >> 2) & 0x33333333) + (x & 0x33333333));
    x = (((x >> 4) + x) & 0x0f0f0f0f);
    x += (x >> 8);
    x += (x >> 16);
    return x & 0x0000003f; //15
}

int main() 
{
  unsigned target = 7;
  printf("Kernighan Count = %d \n", kernighanCount(target));
  printf("Built In Count = %d \n", builtInCount(target));
  printf("Mask Count = %d \n", maskCount(target));
  printf("Population Count = %d \n", populationCount(target));
}

