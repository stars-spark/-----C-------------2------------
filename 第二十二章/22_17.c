#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  FILE *fp;
  char ch;
  char number[15];
  int i = 1;

  if (argc != 2) {
    fprintf(stderr, "usage: read sourcefile\n");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf (stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  number[0] = '(';

  while((ch = fgetc(fp)) != EOF) {
	if(isdigit(ch)&&i<15) number[i++] = ch;
	if(i == 4) number[i++] = ')';
	if(i == 5) number[i++] = ' ';
	if(i == 9) number[i++] = '-';
	if(ch == '\n'){
		puts(number);
		i = 1;
	  }
	
	}
  
  fclose(fp);
  return 0;
}
