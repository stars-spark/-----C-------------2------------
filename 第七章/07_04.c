#include <stdio.h>

int main(void){
  char c;
  printf("Enter phone number: ");
  
  while((c = getchar()) != '\n'){
    if(c >= 'A' && c <='C')printf("%d",2);
    else if(c >= 'D' && c <='F')printf("%d",3);
    else if(c >= 'G' && c <='I')printf("%d",4);
    else if(c >= 'J' && c <='L')printf("%d",5);
    else if(c >= 'M' && c <='O')printf("%d",6);
    else if(c >= 'P' && c <='S')printf("%d",7);
    else if(c >= 'T' && c <='V')printf("%d",8);
    else if(c >= 'W' && c <='Z')printf("%d",9);
    else printf("%c",c);
  }
  return 0;
}
