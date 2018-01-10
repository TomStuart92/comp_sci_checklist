#include <stdio.h>

#define     LOWER    0.0
#define     UPPER    1000.0
#define     STEP     50.0

int main() {
    printf("Farenheit\tCelsius\n");
    float fahr;
    for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        float celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);
    }
}