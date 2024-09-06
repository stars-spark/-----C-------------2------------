#include <stdio.h>
int main(void){
  char sentence[100];
  char c;
  char* p = sentence;
  *p++ = ' ';
  printf("Enter a sentence: ");
  c = getchar();
  while(c != '.'&& c != '!' && c!='?'){
    *p++ = c;
    c = getchar();
  }

  printf("Reversal of sentence: ");
  p--;
  while(p > sentence){
    int i = 0;
    while(*(p--) != ' ')i++;
    for(int k = 2; k <= i+2; k++)
      printf("%c",*(p + k));
  }
  printf("%c",c);
  
  return 0;
}
