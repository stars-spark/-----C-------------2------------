#include <stdio.h>

float power(float x, int n);
float polynomial(float x);

int main(){
float f;
printf("Enter a number:");
scanf("%f",&f);
printf("The result is %f.",polynomial(f));

}

float power(float x, int n){
  float result = 1;
  for(int i = 1; i <= n; i++) result*=x;
  return result;
}
float polynomial(float x){

return (3*x*x*x*x*x +2*x*x*x*x - 5*x*x*x - x*x + 7*x -6);  
}
/*
float polynomial(float x){

return (3*power(x,5) +2*power(x,4) - 5*power(x,3) - power(x,2) + 7*x -6);  
}
*/ 
}
