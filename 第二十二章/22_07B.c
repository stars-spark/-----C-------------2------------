#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  FILE *fp, *fop;
  char ch;
  int count = 0;

  if (argc != 3) {
    printf("usage: uncompress filename filename\n");
    exit (EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "rb")) == NULL) {
   	printf("%s can’t be opened.\n", argv[1]);
		exit (EXIT_FAILURE);	
	}

  if ((fop = fopen(argv[2], "wb")) == NULL) {
   printf("%s can’t be opened.\n", argv[2]);
	exit (EXIT_FAILURE);	
	}

  while((count = fgetc(fp)) != EOF){
	  ch = fgetc(fp);
	  for(int i = 0; i < (int)count; i++)
		fputc(ch,fop);
	}

  fclose(fp);
  fclose(fop);
  return 0;
}
