#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
  FILE *fp;
  char ch;
  int count = 0;

  if (argc < 2) {
    printf("usage: fcat filename filename...\n");
    exit (EXIT_FAILURE);
  }
  
  	for(int i = 2; i < argc; i++){
		if ((fp = fopen(argv[i], "r")) == NULL) {
    		printf("%s can’t be opened.\n", argv[i]);
			count++;
			continue;	
	  	}
		printf("%s can be opended.\n", argv[i]);
		fclose(fp);
  	}

	if(count == argc - 1) {
	 	printf("All file can't be opeded.\n");
	  	exit (EXIT_FAILURE);
	 }

	if(count != 0) printf("%d file can't be opeded, cat others.\n",count);
	
	for(int i = 2; i < argc; i++)	{
	  if ((fp = fopen(argv[i], "r")) != NULL) 
		while((ch = fgetc(fp)) != EOF) fputc(ch,stdout);
	  fclose(fp);
	}
  return 0;
}
