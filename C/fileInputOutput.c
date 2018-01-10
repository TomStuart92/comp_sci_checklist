#include <stdio.h>

int replaceNonWord(int character) {
    if (character == '\n')
        return 'n';
    if (character == '\t')
        return 't';
    if (character == ' ')
        return 's';
    return character;
}

int main() {
    int c;
    int nl = 0;
    int nt = 0;
    long nc = 0;
    long ns = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++nt;
        if (c == ' ')
            ++ns;
        
        putchar(replaceNonWord(c));
    }
    printf("Number of Characters: %ld\n", nc);
    printf("Number of Lines: %d\n", nl);
    printf("Number of Tabs: %d\n", nt);
    printf("Number of Spaces: %ld\n", ns);
    
}