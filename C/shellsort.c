#include <stdio.h>

void swap(int v[], int i, int j) {
    int temp;
    temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}


void shellsort(int v[], int n)
{
    int gap, i, j;

    for (gap = n/2; gap > 0; gap /= 2) 
        for (i = gap; i < n; i++)
            for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
                swap(v, j, j+gap);
            }
}

int main() {
    int i;
    int a[5] = {4, 2, 5, 1, 3};

    shellsort(a, 5);

    for (i = 0; i < 5; i++)
        printf("%d\n", a[i]);
}