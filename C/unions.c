#include <stdio.h>

// u_tag can be either int, float or char*;

union u_tag {
  int ival;
  float fval;
  char *sval;
} u;

int main() {
  u.ival = 10;
  printf("%d\n", u.ival);
  printf("%f\n", u.fval);
  u.fval = 1.0;
  printf("%d\n", u.ival);
  printf("%f\n", u.fval);
}