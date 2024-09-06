#include <stdio.h>

int main(void){
  char ch;
  char pnumber[15] = {'\0'};
  printf("Enter phone number: ");
  int i = 0;
  while((ch = getchar()) != '\n'){
    if(ch >= 'A' && ch <='C') ch = '2';
    else if(ch >= 'D' && ch <='F') ch = '3';
    else if(ch >= 'G' && ch <='I') ch = '4';
    else if(ch >= 'J' && ch <='L') ch = '5';
    else if(ch >= 'M' && ch <='O') ch = '6';
    else if(ch >= 'P' && ch <='S') ch = '7';
    else if(ch >= 'T' && ch <='V') ch = '8';
    else if(ch >= 'W' && ch <='Z') ch = '9';
    pnumber[i++] = ch;
  }
  printf("In numerich form: ");
  for(int i = 0; i < 15; i++)
    if(pnumber[i]!='\0') putchar(pnumber[i]);
  return 0;
}
