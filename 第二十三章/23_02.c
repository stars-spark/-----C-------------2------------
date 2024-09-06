#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(void){
  char ch;
  bool start = false;
  FILE* fp;
  char fname[50];

  printf("Enter file name: ");
  scanf("%s",fname);
  if((fp = fopen(fname,"r")) == NULL ){
	  printf("Cann't open file %s.",fname);
	  exit(EXIT_FAILURE);
	}

  while((ch = fgetc(fp)) != EOF) {
  //先从文件流中读取数据
		if(ch !='\n') {
			while(!start && isblank(ch)) ch = fgetc(fp);
			start = true;
			putchar(ch);
    		//判断、删除空白后输出到标准输出中
	  }else{
		putchar('\n');
		start = false;
	  } 
	}
	fclose(fp);
  return 0;
  }
