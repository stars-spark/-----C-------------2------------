#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  FILE *fwp,*fup;
  char current, next;
  
  if (argc != 3) {
    fprintf(stderr, "usage: u2w file1 file2.\n");
    exit(EXIT_FAILURE);
  }

  if ((fup = fopen(argv[1], "rb")) == NULL) {
    fprintf (stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((fwp = fopen(argv[2], "wb")) == NULL) {
    fprintf (stderr, "Can't open %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  while((current = fgetc(fup))!= EOF)  {
		if(current == '\x0a') fputc('\x0d',fwp);		
		fputc(current,fwp);  
  }

  fclose(fwp);
  fclose(fup);
  return 0;
}
