#include <stdio.h>
#include <string.h>
#define MAX 100

void reverse(char *message);

int main(void){
  char str[MAX];
  char ch;
  int i = 0;

  printf("Enter a message: ");
  while((ch = getchar())!='\n' && i < MAX)
    str[i++] = ch;
  reverse(str);
  printf("Reversal is: %s",str);
  return 0;
}

void reverse(char *message){
  char* phead = message;
  char* ptail = message+strlen(message) - 1;
  char temp;
  while(phead!=ptail){
	  temp = *phead;
	*phead = *ptail;
	*ptail = temp;
	phead++;
	ptail--;
	}
  }
