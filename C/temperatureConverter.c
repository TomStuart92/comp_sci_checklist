#include <stdio.h>

#define     LOWER    0.0
#define     UPPER    1000.0
#define     STEP     50.0

float convertFarenheitToCentigrade(float farenheit);

float convertFarenheitToCentigrade(float farenheit) {
    return (5.0 / 9.0) * (farenheit - 32.0);
}

int main() {
    printf("Farenheit\tCelsius\n");
    float fahr;
    for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        float celsius = convertFarenheitToCentigrade(fahr);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);
    }
}