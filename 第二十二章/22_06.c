#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  FILE *fp;
  char ch;
  int count = 0;
  int endoffile = 0;

  if (argc != 2) {
    printf("usage: list filename \n");
    exit (EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "rb")) == NULL) {
   printf("%s can’t be opened.\n", argv[1]);
	exit (EXIT_FAILURE);	
	}
  printf("Offset               Bytes               Characters\n");
  printf("------   -----------------------------   ----------\n");
  
  while(endoffile != 1)	{
	  count++;
	  printf("%6d   ",count*10);
	  for(int i = 0 ;i <10; i++){
			if((ch = fgetc(fp)) == EOF) {
				endoffile = 1;
				for(;i <10; i++) printf("  ");
				break;
			}
			printf("%02X ",ch);
		}

	  fseek(fp,-10,SEEK_CUR);
	  printf("\t ");

	  for(int i = 0 ;i <10; i++){
		  if((ch = fgetc(fp)) == EOF) {
				endoffile = 1;
				for(;i <10; i++) printf(" ");
				break;
				}
		  	if(!isprint(ch))printf(".");
			else printf("%c",ch);
		  } 
			printf("\n");
	  }
	
  return 0;
}
