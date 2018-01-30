#include <stdio.h>

// #define KEYWORD 01
// #define EXTERNAL 02
// #define STATIC 04

enum {
  KEYWORD = 01,
  EXTERNAL = 02,
  STATIC = 04
};

//define a set of 1 bit fields;
struct {
  unsigned int is_keyword  : 1;
  unsigned int is_extern   : 1;
  unsigned int is_static   : 1;
} flagFields;

int main() {
  int flags = 0;
  flags |= EXTERNAL | STATIC;      // turns on EXTERNAL and STATIC BITS
  flags &= ~(EXTERNAL | STATIC);   // turns off EXTERNAL and STATIC
  if ((flags & (EXTERNAL | STATIC)) == 0) // print if bits off
    printf("Flags False\n");

  flagFields.is_extern = flagFields.is_static = 1;  // turns on EXTERNAL and STATIC BITS
  flagFields.is_extern = flagFields.is_static = 0;  // turns off EXTERNAL and STATIC BITS
  if (flagFields.is_extern == 0 && flagFields.is_static == 0) // print if bits off
    printf("Flags False\n");
}
