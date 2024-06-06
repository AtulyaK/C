#include "temp.h"
#include <stdio.h>

void main() {
  printf("Enter a tempreature in Fahrenheit:");
  double fahrenheit;
  double celsius = celsius(scanf("%lf",&fahrenheit));
  printf("%f",celsius);
}

double celsius(double fahrenheit) {
  return (5*(fahrenheit - 32) / 9);
}
