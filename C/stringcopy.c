#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void stringcopy(char *s, char *t)
{
    while((*s++ = *t++))
        ;
}

int main()
{
    char *message = "hello";
    char *target = malloc(strlen(message) + 1);
    stringcopy(message, target);
}