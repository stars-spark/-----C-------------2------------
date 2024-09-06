#include <stdio.h>
#define MAX 100

int main()
{
	char str[MAX];
	char ch, *p = str;
	printf("Enter a message: ");
	while((ch = getchar())!='\n')
		*p++ = ch;
	printf("Reversal is: ");
	while( p >= str) printf("%c",*p--);
		
	return 0;
}

