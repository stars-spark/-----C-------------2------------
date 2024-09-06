
/* Checks numbers for repeated digits */

#include <stdbool.h>	/* C99 only */
#include <stdio.h>

int main(void){
  int digit_seen[10] = {0};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    digit_seen[digit]++;
    n /= 10;
  }
printf("Repeated digit(s): "); 
for(int i = 0; i< 10;i++)
  if(digit_seen[i]>1) printf("%d ",i);

return 0;
}
