#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void){
  char ch;
  bool checked = false;
  int count = 0;
  FILE* fp;
  char fname[50];

  printf("Enter file name: ");
  scanf("%s",fname);

  if((fp = fopen(fname,"r")) == NULL ){
	  printf("Cann't open file %s.",fname);
	  exit(EXIT_FAILURE);
	  }

  while((ch = fgetc(fp)) != EOF) {
		if(strchr(",、?!",ch) != NULL) checked =true;
		if((ch == ' '||ch == '\n' ) && checked) {
	  		count++;
	  		checked = false;
	  	}
  	}

	fclose(fp);
  return 0;
  }
