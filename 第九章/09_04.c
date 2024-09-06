#include <stdio.h>
#include <stdbool.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void){
	int fwords[26] = {0};
	int swords[26] = {0};
	
	read_word(fwords);
	read_word(swords);
	if(equal_array(fwords,swords)) printf("The words are anagrams.");
		else printf("The words are not anagrams.");
	return 0;
}

void read_word(int counts[26]){
	char ch;
	printf("Enter the word: ");
	while((ch = getchar()) != '\n' && isalpha(ch)) counts[toupper(ch) - 'A']++;

}
bool equal_array(int counts1[26], int counts2[26])
{
	for(int i = 0 ; i < 26; i++){
		if(counts1[i] != counts2[i])
				return false;
	}
	return true;
}
