#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
  FILE *fp;
  char ch;

  if (argc != 2) {
    printf("usage: UpperChar filename\n");
    exit (EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("%s can’t be opened.\n", argv[1]);
	  exit (EXIT_FAILURE);	
	  }

  while((ch = fgetc(fp)) != EOF){
  		if(isalpha(ch)) fputc(toupper(ch),stdout);
  		else fputc(ch,stdout);
  	} 

  fclose(fp);
  return 0;
}
