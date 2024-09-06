#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool are_anagrams(const char *word1, const char *word2);
int main(void){
	char word1[20],word2[20];
	printf("Enter first word: ");
	scanf("%s",word1);
	printf("Enter second word: ");
  	scanf("%s",word2);
	if(are_anagrams(word1,word2))
	  printf("The words are anagrams.");
	else
	  printf("The words are NOT anagrams.");
	return 0;
}
bool are_anagrams(const char *word1, const char *word2){
  	int words[26] = {0};
	for(int i = 0;i < strlen(word1);i++){	
	  if(isalpha(*(word1 + i))) words[toupper(*(word1 + i)) - 'A']++;
	}
	
	for(int i = 0;i < strlen(word2);i++){	
	  if(isalpha(*(word2 + i))) words[toupper(*(word2 + i)) - 'A']--;
	}
	
	for(int i = 0 ; i < 26; i++){
	  if(words[i] != 0) return false;
	}
	return true;
  }

