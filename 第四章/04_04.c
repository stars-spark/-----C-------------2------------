#include <stdio.h>

int main(void){
	int number, r1,r2,r3,r4,r5;
	printf("Enter a number between 0 and 32767: ");
	scanf("%d",&number);
	r5 = number % 8;
	number = number / 8;
	r4 = number % 8;
	number = number / 8;
	r3 = number % 8;
	number = number / 8;
	r2 = number % 8;
	number = number / 8;	
	r1 = number % 8;
	number = number / 8;
	printf("In octal, your number is: %d%d%d%d%d",r1,r2,r3,r4,r5);

  return 0;
}
