#include <stdio.h>

int power(int m, int n);

int power(int base, int exponent) {
    int p;

    for (p = 1; exponent > 0; --exponent)
        p = p * base; 
    return p;
}

int main() {
    int i;
     printf("i\t2^i\t-3^i\n");
    for(i = 0; i < 10; ++i)
        printf("%d\t%d\t%d\n", i, power(2,i), power(-3,i));
    return 0;
}