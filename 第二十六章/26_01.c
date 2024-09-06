#include <stdio.h>
#include <stdlib.h>

int main(void){
	/*
	srand((unsigned)time(NULL));
	注释该行代码后，程序运行的输出是确定的。
	*/
	for(int i = 0; i < 100 ;i++){
		printf("%d",rand()%2 == 0 ? 0:1 );
	}
  return 0;
  }
