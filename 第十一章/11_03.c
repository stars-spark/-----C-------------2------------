#include <stdio.h>
void reduce(int numerator, int denominator,
					int *reduced_numerator,
					int *reduced_denominator);

int main(void){
 int top, bottom;
 printf("Enter a fraction: : "); 
 scanf("%d/%d",&top,&bottom);
 reduce(top, bottom,&top,&bottom);
 printf("In lowest terms: %d/%d",top,bottom);
return 0;
}
void reduce(int numerator, int denominator, 
            int *reduced_numerator, 
            int *reduced_denominator)
{
    int remainder;

    while(denominator != 0){
        remainder = numerator%denominator;
        numerator = denominator;
        denominator = remainder;					
    }

    *reduced_numerator /= numerator;
    *reduced_denominator /= numerator;
}
