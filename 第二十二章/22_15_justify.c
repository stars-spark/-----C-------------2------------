//justify.c
/* Formats a file of text */

#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void){
  char word[MAX_WORD_LEN+2];
  int word_len;

  FILE* fip, *fop;
  char fname[20];

  printf("Enter name of file to be read:  ");
  scanf("%s",fname);
  if((fip = fopen(fname,"r")) == NULL)  {
	  printf("Cann't open file %s.",fname);
	  exit(EXIT_FAILURE);
  }

  printf("Enter name of file to be writen:  ");
  scanf("%s",fname);
  if((fop = fopen(fname,"w")) == NULL)  {
	  printf("Cann't open file %s.",fname);
	  exit(EXIT_FAILURE);
  }

  clear_line();
  for (;;) {
    read_word(fip, word, MAX_WORD_LEN+1);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line(fop);
      return 0;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line(fop);
      clear_line();
    }
    add_word(word);
  }
}
