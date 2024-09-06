/* Performs XOR encryption */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[]){
  int orig_char, new_char;
  FILE *fop, *fnp;

  if (argc != 3) {
    printf("usage: xor filename \n");
    exit (EXIT_FAILURE);
  }

  if ((fop = fopen(argv[1], "rb")) == NULL) {
    printf("%s can’t be opened.\n", argv[1]);
	exit (EXIT_FAILURE);	
	}

  if ((fnp = fopen(argv[2], "wb")) == NULL) {
    printf("%s can’t be opened.\n", argv[2]);
	exit (EXIT_FAILURE);	
	}

  while ((orig_char = fgetc(fop)) != EOF) {
    new_char = orig_char ^ KEY;
	fputc(new_char,fnp);
  }
	fclose(fop);
	fclose(fnp);
  return 0;
}
