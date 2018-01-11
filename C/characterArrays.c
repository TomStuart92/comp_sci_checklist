#include <stdio.h>

#define  MAXLINE  1000      /* Define maximum size of input line */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

// Print Longest Input Line

int main() {
    int len;                // current line length
    int max;                // maximum lenght seen so far
    char line[MAXLINE];     // current input line
    char longest[MAXLINE];  // longest line saved here.

    max = 0;

    while((len = getLine(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("longest: %s\n", longest);
    return 0;
}

int getLine(char s[], int limit) {
    int c, i;

    for (i = 0; i < (limit - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i] != '\0')) 
        ++i;
}

