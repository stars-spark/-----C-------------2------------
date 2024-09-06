#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void){
  char ch;
  FILE* fp;
  char fname[50];

  printf("Enter file name: ");
  scanf("%s",fname);

  if((fp = fopen(fname,"r")) == NULL ){
	  printf("Cann't open file %s.",fname);
	  exit(EXIT_FAILURE);
	  }

  while((ch = fgetc(fp)) != EOF)  {
		if(iscntrl(ch)&&ch!='\n') putchar('?');
		else putchar(ch);
  }
	fclose(fp);
  return 0;
  }

