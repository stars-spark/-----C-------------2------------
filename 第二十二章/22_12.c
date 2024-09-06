#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
  int number;
  float price;
  int day, month, year;
  FILE* fp;
  char fname[20];

  printf("Enter file name: ");
  scanf("%s",fname);
  if((fp = fopen(fname,"r")) == NULL ) {
	  printf("Cann't open file %s.",fname);
	  exit(EXIT_FAILURE);
	  }

  printf("Item\t\tUnit\t\tPurchase\n");
  printf("\t\tPrice\t\tdate\n");
	while(fscanf(fp,"%d,%f,%d/%d/%d",&number,&price,&day,&month,&year) == 5)
	{
	  printf("%-d\t\t$%7.2f\t%-02d/%-02d/%-04d",number,price,month,day,year);
	}
fclose(fp);	  
return 0;
}
