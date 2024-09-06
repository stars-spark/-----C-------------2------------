#include <stdio.h>
#define MAX 100

int main()
{
  char str[MAX];
  char ch;
  int i = 0;
  printf("Enter a message: ");
  while((ch = getchar())!='\n' && i < MAX)
    str[i++] = ch;
  printf("Reversal is: ");
  while( i-- > 0) printf("%c",str[i]);
    
  return 0;
}
