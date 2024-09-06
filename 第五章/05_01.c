#include <stdio.h>

int main(void){
	int digit = 0;
	printf("Enter a number:");
	scanf("%d",&digit);
	if(digit>=0 && digit<=9)//判断是否一位数
		printf("The number %d has 1 digits",digit);
	else if(digit>=10 && digit<=99) //判断是否两位数
		printf("The number %d has 2 digits",digit);
	else if(digit>=100 && digit<=999) //判断是否三位数
		printf("The number %d has 3 digits",digit);
	else //剩余大于等于四位数
		printf("The number %d has 4 or more digits",digit);

  return 0;
}
