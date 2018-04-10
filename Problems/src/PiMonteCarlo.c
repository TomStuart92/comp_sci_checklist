// The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.
// Hint: The basic equation of a circle is x2 + y2 = r2.

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define RADIUS 1.0
#define STABLE_THRESHOLD 1000000
#define TARGET_ACCURACY 4

double estimate_pi(double inside, double total)
{
  return 4 * ( inside / total );
}

double random_point() 
{
   return (double) rand() / (double) RAND_MAX ;
}

bool in_circle(double x, double y)
{
  return pow(x, 2) + pow(y, 2) <= pow(RADIUS, 2);
}

int extract_target_decimal(double pi)
{
  return (int) (pi * pow(10, TARGET_ACCURACY)) % 10;
}

int main() 
{
  int inside = 0;
  int total = 0;
  double pi = 0.0;
  
  int last_decimal = 0;
  int stable_count = 0;

  while(stable_count < STABLE_THRESHOLD) 
  {
    total++;
    double x = random_point();
    double y = random_point();
    if(in_circle(x, y))
      inside++;
    pi = estimate_pi(inside, total);

    int target_digit = extract_target_decimal(pi);
    if(target_digit == last_decimal)
      stable_count++;
    else {
      stable_count = 0;
      last_decimal = target_digit;
    }
  }

  printf("Final Value: %f\n", pi);
  printf("Total Trials: %d\n", total);
}