#include <stdio.h> 

int main() {
  printf("\nAND OP (&)\n");
  printf("0 & 0 = %d\n", 0 & 0);
  printf("0 & 1 = %d\n", 0 & 1);
  printf("1 & 0 = %d\n", 1 & 0);
  printf("1 & 1 = %d\n", 1 & 1);

  printf("\nOR OP (|)\n");
  printf("0 | 0 = %d\n", 0 | 0);
  printf("0 | 1 = %d\n", 0 | 1);
  printf("1 | 0 = %d\n", 1 | 0);
  printf("1 | 1 = %d\n", 1 | 1);

  printf("\nXOR OP (^)\n");
  printf("0 ^ 0 = %d\n", 0 ^ 0);
  printf("0 ^ 1 = %d\n", 0 ^ 1);
  printf("1 ^ 0 = %d\n", 1 ^ 0);
  printf("1 ^ 1 = %d\n", 1 ^ 1);

  printf("\nNOT OP (~)\n");
  printf("~0 = %u\n", ~0);
  printf("~1 = %u\n", ~1);

  printf("\nLEFT SHIFT (<<)\n");
  // pads on end operand times. same as multiplication by 2 excluding overflows. 
  printf("00010110 (22) << 00000010 (2) = 01011000(%d) \n", 22 << 2);

  printf("\nRIGHT SHIFT (>>)\n");
  // pads on start operand times. same as division rounded down.
  printf("00010110 (22) << 00000010 (2) = 00000101(%d) \n", 22 >> 2);
}