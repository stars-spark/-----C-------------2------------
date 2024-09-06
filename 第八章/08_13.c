#include <stdio.h>
int main(void){
  char ch;
  int start = 0;
  char fname[15]={'\0'};
  int i = 0;
  printf("Enter a first and last name: ");
  while((ch = getchar())!='\n'){
    if(ch != ' ' ) fname[i++] = ch;
    else break;
  }
  printf("You enered the name: " );
  while((ch = getchar())!='\n') putchar(ch);
  printf(", %c ",fname[0]);
  return 0;
}
