#include <stdio.h>
#include <ctype.h>
int read_line(char str[], int n);
int compute_vowel_count(const char *sentence);

int main(void){
  char sentence[100];

  printf("Enter a sentence: ");
  read_line(sentence,100);
  puts(sentence);
  printf("Your sentence contains %d vowels.",compute_vowel_count(sentence));
  return 0;
}

int read_line(char str[], int n){
  int ch, i = 0;

  while ((ch = getchar()) != '\n' && ch != EOF)
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}

int compute_vowel_count(const char *sentence){
  int counter = 0;
  int i = 0;
  char c = *(sentence + i++);
  while(c!='\0'){
    c = toupper(c);
    if(c == 'A'||c == 'E'||c == 'I'||c == 'O'||c == 'U') counter++;
	c = *(sentence + i++);
  }
  return counter;
 }
