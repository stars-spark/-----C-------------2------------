#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100

bool palindrome(const char a[], int n);

int main(void){
	char str[MAX];
	char ch;
	int i = 0;

	printf("Enter a message: ");
	while((ch = getchar())!='\n' && i < MAX)
		if(isalpha(ch)) *(str + (i++)) = ch;
	if(palindrome(str,i))
		printf("Palindrome.\n");
	else  printf("Not a palindrome.\n");

	return 0;
}

bool palindrome(const char a[], int n){
	int i = 0;
	while( i < n/2) 
	{
		if(toupper(*(a+i)) != toupper(*(a+n-1-i)))
			return false;
		i++;
	}
	return true;
}
