#include <complex.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14

int main(void){ 
  int n;
  double a, b;

  printf("Enter the N:");
  scanf("%d",&n);
  for(int i = 0; i<n;i++){
		a = cos(2*i*PI/n);
		b = sin(2*i*PI/n);
		if(b > 0)
	  		printf("The No.%3d root is %.2lf + %.2lfi\n",i,a,fabs(b));
		else 	  
   		printf("The No.%3d root is %.2lf - %.2lfi\n",i,a,fabs(b));
}
  return 0;
}
