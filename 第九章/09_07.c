#include <stdio.h>
int power(int x, int n);

int main(void){
  int m,n;
  printf("Enter two number to calc power:");
  scanf("%d %d",&m,&n);
  printf("The result is %d ",power(m,n));
  return 0;
}

int power(int x, int n){
  int result = 1;
  if(n == 0) return result;
  if(n%2!=0) result = x*power(x,n-1);
  else result = power(x,n/2)*power(x,n/2);
  return result;
}

