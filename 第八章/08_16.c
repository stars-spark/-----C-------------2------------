#include <stdio.h>
#include <ctype.h>
int main(void){
	int words[26] = {0};
	char ch;
	printf("Enter first word: ");
	while((ch = getchar()) != '\n' && isalpha(ch)) words[toupper(ch) - 'A']++;
	printf("Enter second word: ");
	while((ch = getchar()) != '\n' && isalpha(ch)) words[toupper(ch) - 'A']--;
	for(int i = 0 ; i < 26; i++){
		if(words[i] != 0){
				printf("The words are not anagrams.");
				return 0;
		}
	}
	printf("The words are anagrams.");
	return 0;
}

