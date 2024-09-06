#include <stdio.h>

int main(void){
  int words = 1;
  int allchars = 0;
  char c;
  printf("Enter a sentence: ");
 while((c = getchar())!='\n'){
    if(c == ' ') words++;
    else allchars++;
  }
  printf("Average word length: %.1f\n",1.0*allchars/words);
  return 0;
}
