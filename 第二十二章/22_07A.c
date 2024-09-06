#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  FILE *fp, *fcp;
  char current, next;
  char* fn;
  int count = 0;

  if (argc != 2) {
    printf("usage: compress filename \n");
    exit (EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "rb")) == NULL) {
  		printf("%s can’t be opened.\n", argv[1]);
	  	exit (EXIT_FAILURE);	
	}

  fn = malloc((strlen(argv[1]+5))*sizeof(char));
  if(fn == NULL) exit (EXIT_FAILURE);

  strcpy(fn,argv[1]);
  strcat(fn,".rle");

  if ((fcp = fopen(fn, "wb")) == NULL) {
   printf("%s can’t be opened.\n", fn);
	exit (EXIT_FAILURE);	
	}

  while((current = fgetc(fp)) != EOF)	{
	  count = 1;
	  while((next =fgetc(fp)) != EOF){
			if(next == current) count++;
			else break;
		}
	  printf("%d    ",count);
	  ungetc(next,fp);
	  fputc((char)count,fcp);
	  fputc(current,fcp);
	}

  free(fn);
  fclose(fp);
  fclose(fcp);
  return 0;
}
