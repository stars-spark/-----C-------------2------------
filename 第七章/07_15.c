#include <stdio.h>
#include <math.h>
int main(void){
  int n,result = 1;
  
  printf("Enter a positive integer: ");
  scanf("%d",&n);
  for(int i = 1 ; i<=n; i++){
    result *= i;
  }
  printf("Factorial of %d: %d",n, result);
  return 0;
}
