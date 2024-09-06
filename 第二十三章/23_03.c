#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(void){
  char ch;
  bool start = true;
  FILE* fp;
  char fname[50];

  printf("Enter file name: ");
  scanf("%s",fname);
  if((fp = fopen(fname,"r")) == NULL ){
	  printf("Cann't open file %s.",fname);
	  exit(EXIT_FAILURE);
	 }
  while((ch = fgetc(fp)) != EOF){
		if(ch !='\n') {
			if(isblank(ch)) start = true;
			if(isalpha(ch)&&start){
		  	putchar(toupper(ch));
		  	start = false;
		 }
			else putchar(ch);
	  }
	}

	fclose(fp);
  return 0;
  }
