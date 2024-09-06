#include <stdio.h>

int main(void){
  double lf, sum = 0;
  
  printf("This program sums a series of double number.\n");
  printf("Enter integers (0 to terminate): ");

  scanf("%lf", &lf);
  while (lf != 0) {
    sum += lf;
    scanf("%lf", &lf);
  }
  printf("The sum is: %lf\n", sum);

  return 0;
}
