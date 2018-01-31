#include <stdio.h>

unsigned setBit(unsigned x, unsigned position) 
{
  unsigned mask = 1 << position;
  return x | mask;
}

unsigned clearBit(unsigned x, unsigned position) 
{
  unsigned mask = 1 << position;
  return x & ~mask;
}

unsigned flipBit(unsigned x, unsigned position) 
{
  unsigned mask = 1 << position;
  return x ^ mask;
}

unsigned isSetBit(unsigned x, unsigned position) 
{
  unsigned shifted = x >> position;
  return shifted & 1;
}

unsigned modifyBit(unsigned x, unsigned position, unsigned state)
{
  unsigned mask = 1 << position;
  return (x & ~mask) | (-state & mask);
}

int main() {
  printf("\nBit Masks\n");
  unsigned x = 6;
  unsigned position = 5;
  printf("setting 5th bit in 00000101 (6) = 00010101 (%d)\n", setBit(x, position));
  printf("clearing 5th bit in 00010101 (38) = 00000101 (%d)\n", clearBit(x, position));

  printf("flipping 5th bit in 00000101 (6) = 00010101 (%d)\n", flipBit(x, position));
  printf("flipping 5th bit in 00010101 (38) = 00000101 (%d)\n", flipBit(flipBit(x, position), position));

  printf("check if 5th bit in 00000101 (6) is set = %d\n", isSetBit(x, position));
  printf("check if 5th bit in 00010101 (38) is set = %d\n", isSetBit(flipBit(x, position), position));

  printf("modify 5th bit in 00000101 (6) = 00010101 (%d)\n", modifyBit(x, position, 1));
  printf("modify 5th bit in 00010101 (38) = 00000101 (%d)\n", modifyBit(x, position, 0));
}
