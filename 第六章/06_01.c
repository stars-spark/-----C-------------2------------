#include <stdio.h>

int main(void){
 	float number, max = 0;
	printf("Enter a number:"); 
 	scanf("%f",&number);
 	max = number;
	while(number > 0){
 			printf("Enter a number:"); 
 			scanf("%f",&number);
 			if(number > max) max = number;
 	}
 	printf("The largest number entered was %g",max);
	return 0;
}
