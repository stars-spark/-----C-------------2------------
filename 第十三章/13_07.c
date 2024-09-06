#include <stdio.h>

int main(void)
{
  int number;
  const char digit_one[][10] = {"","One","Two",
                        "Three","Four","Five","Six","Seven","Eight","Nine"};
  const char digit_two[][10] =  {"", "", "Twenty-", "Thirthy-", 
                       "Forty-", "Fifty-", "Sixty-", "Seventy-", "Eighty-", "Ninety"};
  const char ten[][10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
                       "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
  int  one_digit,two_digit;
  printf("Enter a two-digit number: ");
  scanf("%d", &number);
  printf("You entered the number ");
  if(number>=20 || number < 10){
  		two_digit = number / 10;
  		one_digit = number %10;
		printf("%s%s",digit_two[two_digit],digit_one[one_digit]);
	}else{
		printf("%s",ten[number-10]);
	  	}
 return 0;
}
