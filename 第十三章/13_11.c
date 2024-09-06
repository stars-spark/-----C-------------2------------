#include <stdio.h>

double compute_average_word_length(const char *sentence);
int read_line(char str[], int n);

int main(void){
  char str[100];

  printf("Enter a sentence: ");
  read_line(str,100);
  printf("Average word length: %.1f\n",compute_average_word_length(str));
  return 0;
}

double compute_average_word_length(const char *sentence){
  int words = 1;
  int allchars = 0;
  int i = 0;
  char c = *sentence;

 while(c !='\0'){
    if(c == ' ') words++;
	else allchars++;
	i++;
	c = *(sentence + i);
  }
  return 1.0*allchars/words;
}

int read_line(char str[], int n){
  int ch, i = 0;

  while ((ch = getchar()) != '\n' && ch != EOF)
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
  }
