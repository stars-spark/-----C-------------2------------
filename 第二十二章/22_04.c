#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
  FILE *fp;
  char ch;
  int char_count = 0;
  int word_count = 0;
  int line_count = 1;

  if (argc != 2) {
    printf("usage: fstat filename \n");
    exit (EXIT_FAILURE);
  }
  
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("%s can’t be opened.\n", argv[1]);
	exit (EXIT_FAILURE);	
	}

	while((ch = fgetc(fp)) != EOF)	{
	  char_count++;
	  if(isblank(ch)) word_count++;
	  if(ch == '\n') line_count++;
	 }

   fclose(fp);
   printf("%d chars , %d words and %d lines in file.\n",
        char_count,word_count,line_count);  
   return 0;
}
