#include <stdio.h>
#include <stdlib.h>
int main(void){
  int  hour, minute;
  int input_minutes;
  int departure[8] ,arriving[8];
  int dh,dm,ah,am;
  FILE* fp;

  if((fp = fopen("flights.dat","r")) == NULL)	{
	  printf("Cann't open file.");
	  exit(EXIT_FAILURE);
	}

  for(int i = 0 ; i < 8 ; i++){
	  fscanf(fp,"%d:%d %d:%d",&dh,&dm,&ah,&am);
	  departure[i] = dh*60+dm;
	  arriving[i] = ah*60+am;
	}
	
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &minute);
  input_minutes = hour*60+minute;
	if (input_minutes<(departure[0]+departure[7])/2){
		printf("Closet departure time is %d:%d AM,arriving at %d:%d AM", 
	  departure[7]/60, departure[7]%60,arriving[7]/60,arriving[7]%60);
	}
	else if(input_minutes<(departure[0]+departure[1])/2){
		printf("Closet departure time is %d:%d AM,arriving at %d:%d AM", 
	  departure[0]/60, departure[0]%60,arriving[0]/60,arriving[0]%60);
	}
	else if(input_minutes<(departure[1]+departure[2])/2){
		printf("Closet departure time is %d:%d AM,arriving at %d:%d AM", 
	  departure[1]/60, departure[1]%60,arriving[1]/60,arriving[1]%60);
	}
	else if(input_minutes<(departure[2]+departure[3])/2){
		printf("Closet departure time is %d:%d AM,arriving at %d:%d AM", 
	  departure[2]/60, departure[2]%60,arriving[2]/60,arriving[2]%60);
	}
	else if(input_minutes<(departure[3]+departure[4])/2){
		printf("Closet departure time is %d:%d AM,arriving at %d:%d AM", 
	  departure[3]/60, departure[3]%60,arriving[3]/60,arriving[3]%60);
	}
	else if(input_minutes<(departure[4]+departure[5])/2){
		printf("Closet departure time is %d:%d AM,arriving at %d:%d AM", 
	  departure[4]/60, departure[4]%60,arriving[4]/60,arriving[4]%60);
	}
	else if(input_minutes<(departure[5]+departure[6])/2){
		printf("Closet departure time is %d:%d AM,arriving at %d:%d AM", 
	  departure[5]/60, departure[5]%60,arriving[5]/60,arriving[5]%60);
	}
	else if(input_minutes<(departure[6]+departure[7])/2){
		printf("Closet departure time is %d:%d AM,arriving at %d:%d AM", 
	  departure[6]/60, departure[6]%60,arriving[6]/60,arriving[6]%60);
	}
	else 
		printf("Closet departure time is %d:%d AM,arriving at %d:%d AM", 
	  departure[7]/60, departure[7]%60,arriving[7]/60,arriving[7]%60);
fclose(fp);
 return 0;
}
