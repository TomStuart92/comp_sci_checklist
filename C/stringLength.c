#include <stdio.h>

int strlength(char *s) 
{
    int n;

    for(n=0; *s != '\0'; s++)
        n++;

    return n;
}

int main() {
    printf("%d\n", strlength("Hello World"));
    printf("%d\n", strlength("World"));
    printf("%d\n", strlength("Hi"));
}