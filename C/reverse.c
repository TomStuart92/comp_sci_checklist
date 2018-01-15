#include <string.h>
#include <stdio.h>


void swap(char s[], int i, int j) {
    int temp = s[j];
    s[j] = s[i];
    s[i] = temp;
}

void reverse(char s[])
{
    int c, i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--) 
       swap(s, i, j);
}

int main() {
    int i;
    char a[5] = "hello";

    reverse(a);
    printf("%s\n", a);
}