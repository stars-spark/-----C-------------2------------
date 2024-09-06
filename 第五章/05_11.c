#include <stdio.h>

int main(void){
  int number;
  int  one_digit,two_digit;

  printf("Enter a two-digit number: ");
  scanf("%d", &number);
  printf("You entered the number ");
  if(number>=20 || number < 10){
  		two_digit = number / 10;
  		one_digit = number %10;
  		switch(two_digit){
  			case 9:printf("Ninety-");
  					break;
  			case 8:printf("Eighty-");
  					break;
  			case 7:printf("Seventy-");
  					break;
			//2~6部分代码略
  			default:printf("……-");
  		}
 		switch(one_digit){
  			case 9:printf("nine");
  					break;
  			case 8:printf("eight");
  					break;
  			case 7:printf("seven");
  					break;
			//1~6部分代码略
  			default:printf("……");
  		}

	  	}else{
	  switch(number){
	  	case 10:printf("Ten");
	  			break;
	  	case 11: printf("Eleven");
	  			break;
	  	case 12:printf("Twelve");
	  			break;
	  	case 13:printf("Thirteen");
	  			break;
	  	case 14:printf("Fourteen");
	  			break;
	  	case 15:printf("Fifteen");
	  			break;
	  	case 16:printf("Sixteen");
	  			break;
	  	case 17:printf("Seventeen");
	  			break;
	  	case 18:printf("Eighteen");
	  			break;
	  	case 19:printf("Nineteen");
	  			break;
	  		}
	  	}
return 0;
}
