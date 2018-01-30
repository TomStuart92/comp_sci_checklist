#include <stdio.h>

int binsearch(int x, int v[], int n ) 
{
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = low + ((high - low) / 2);
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}


int main() {
    int x = 3;
    int v[7] = {1, 2, 3, 4, 5, 6, 7};
    int n = 5;

    int result = binsearch(x, v, n); 

    printf("%d\n", result);
}