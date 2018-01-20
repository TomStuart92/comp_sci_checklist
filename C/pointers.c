#include <stdio.h>

int main() {
    int a[2] = {1,2};
    int *pa = &a[0];
    
    printf("%d\n", *(pa+1));
}