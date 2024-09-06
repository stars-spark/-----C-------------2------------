#include <stdbool.h>	/* C99 only */
#include <stdio.h>

int main(void){
  int digit;
  long n;
  bool digit_seen[10];

  printf("Enter a number: ");
  scanf("%ld", &n);
  while(n > 0){
		for(int i = 0; i < 10 ; i ++) digit_seen[i] = false;
    while (n > 0) {
    digit = n % 10;
    if (digit_seen[digit])
      break;
    digit_seen[digit] = true;
    n /= 10;
    }
    if (n > 0)
    		printf("Repeated digit\n");
  		else
    		printf("No repeated digit\n");
  
	  printf("Enter a number: ");
    scanf("%ld", &n);
  }
  return 0;
}
