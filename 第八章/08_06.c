#include <stdio.h>
#include<ctype.h>
#define LENGTH 100

int main(void){
  char message[LENGTH];
  char c;
  int i = 0; 
  printf("Enter message: ");
  while((c = getchar()) != '\n') message[i++] = c;
  for(int j = 0 ;j < i; j++){
		message[j] = toupper(message[j]);
    if(message[j] == 'A') message[j]  = '4';
    else if(message[j] == 'B') message[j]  = '8';
    else if(message[j] == 'E') message[j]  = '3';
    else if(message[j] == 'I') message[j]  = '1';
    else if(message[j] == 'O') message[j]  = '0';
    else if(message[j] == 'S') message[j]  = '5';
  }
  printf("In B1FF-speak: ");
  for(int j = 0 ;j < i; j++) putchar(message[j]);
  printf("!!!!!!!!!!");
  return 0;
}
