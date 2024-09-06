#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 200

int main(void){
  char Word_List[MAX_LENGTH] = {'\0'};
  char*p, *s = Word_List;
  char ch;
  int i = 0;

  printf("Enter several words: ");
  while((ch = getchar())!='\n') s[i++] = ch;
  s[i] = '\0';
  char* token = strtok(s, " ");
  while(token) token = strtok(NULL, " ");
  s = &Word_List[MAX_LENGTH-1];
  for(p = s - 1;p >= Word_List;p--,s--){
		if(*p == '\0'&& *s != '\0') puts(s);
	}
  puts(s);
  return 0;
  }
