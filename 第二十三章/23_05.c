#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define E 2.71828

int main(void){
  double deposit, rate, year;
  double result;

  printf("Enter the deposit:");
  scanf("%lf",&deposit);
  printf("Enter the rate:");
  scanf("%lf",&rate);
  printf("Enter the year:");
  scanf("%lf",&year);
  result = deposit*pow(E,rate*year);
  printf("At last you will get %.2f.",result);
  
  return 0;
  }
