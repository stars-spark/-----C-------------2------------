#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
  int month, day,year;
  char MONTHS[][8] = 
  {"January", "February", "March", "April", "May",
  "June", "July", "August", "September", "October", 
	"November", "December"};

	if(argc != 2){
  		printf("Usage: conv mm/dd/year, or conv mm-dd-year\n");
  		exit(EXIT_FAILURE);
  	}

  if(sscanf(argv[1], "%d/%d/%d", &month, &day, &year) != 3){
	  if(sscanf(argv[1], "%d-%d-%d", &month, &day, &year) != 3)
		printf("Usage: conv mm/dd/year, or conv mm-dd-year\n");
	}
  printf("%s %d, %d",MONTHS[month-1],day,year);
return 0;
}

