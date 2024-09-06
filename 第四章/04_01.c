#include <stdio.h>
int main(void){
	int number;
	printf("Enter a two-digit number: ");
	scanf("%d",&number);
	printf("The reversal is: %d%d", number%10, number/10);
  return 0;
}	
