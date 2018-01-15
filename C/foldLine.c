#include <stdio.h>

#define  MAXLENGTH  10  
#define  OVERFLOWTHRESHOLD 5

int partitionArray(char input[], char output[], int index);
int arrayLength(char input[]);

int main() {
    int c, i;
    char lineOne[MAXLENGTH];  
    char lineTwo[MAXLENGTH];
    int lastSpace = -1;

    for (i = 0; i <= (OVERFLOWTHRESHOLD) && (c = getchar()) != EOF; ++i) {
        lineOne[i] = c;
        if (c == ' ') {
            printf("\nFound Space\n");
            lastSpace = i;
        }
    }

    if(c == EOF) {
        printf("\nReached EOF, Exiting...\n");
        return 0;  
    }

    if(lastSpace == -1) {    // error: there is no space to fold line on; 
        printf("\nNo Space To Fold\n");
        return 1;
    }

    partitionArray(lineOne, lineTwo, lastSpace);        // move all input from lastspace to overflow threshold to second line
    for (i = arrayLength(lineTwo) + 1; i < (MAXLENGTH - 1) && (c = getchar()) != EOF; i++) {
        lineTwo[i] = c;
    }

    printf("line one: %s\n", lineOne);
    printf("line two: %s\n", lineTwo);
    return 0;
}

int arrayLength(char input[]) {
    return sizeof(input)/sizeof(input[0]);
}

int partitionArray(char input[], char output[], int index) {
    int i;
    for(i = 0; index <= arrayLength(input); index++) {
        output[i++] = input[index];
        input[index] = '\0';
        printf("current output: %s\n", output);
    }
    return 0;
}
