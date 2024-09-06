#include <stdio.h>

typedef union{
  float f;
struct{
  	unsigned int mantissa: 23;
	unsigned int exponent: 8;
 	unsigned int sign: 1;
  } fm;
}FLOAT;


int main(void){
FLOAT ftest;
//ftest.f = -2.0;

ftest.fm.sign = 1;
ftest.fm.exponent = 128;
ftest.fm.mantissa = 0;
printf("%d\n",ftest.fm.sign);
printf("%d\n",ftest.fm.exponent);
printf("%d\n",ftest.fm.mantissa);
printf("%f",ftest.f);
}
