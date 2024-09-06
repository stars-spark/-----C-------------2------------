#include<stdio.h>

int main(void){
	int n;
	float factorial = 1.0;
	float e = 0.0;
	printf("Enter a number to calc e: ");
	scanf("%d", &n);
	for(int i = 1; i<= n;i++){
		factorial = factorial*i;
		e = e + 1.0/factorial;
	}
	printf("The e = %lf\n",e);
 return 0;
}
