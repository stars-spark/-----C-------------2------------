#include <stdio.h>

int main(void){
  int hour, minute;
  int input_minutes;
  char am_pm;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d %c", &hour, &minute,&am_pm);
  if(am_pm == 'A' || am_pm == 'a') input_minutes = hour*60+minute;
  else input_minutes = hour*60+minute + 12*60;
printf("%d",input_minutes);

	if (input_minutes<(615)/2){
		printf("Closet departure time is 9:45 PM,arriving at 11:58 PM");
	}
	else if(input_minutes<(8*60+9*60+43)/2){
		printf("Closet departure time is 8:00 AM,arriving at 10:16 AM");
	}
	else if(input_minutes<(9*60+43+11*60+19)/2){
		printf("Closet departure time is 9:43 AM,arriving at 11:52 AM");
	}
	else if(input_minutes<(11*60+19+12*60+47)/2){
		printf("Closet departure time is 11:19 AM,arriving at 1:31 PM");
	}
	else if(input_minutes<(12*60+47+14*60)/2){
		printf("Closet departure time is 12:47 PM,arriving at 3:00 PM");
	}
	else if(input_minutes<(14*60+15*60+45)/2){
		printf("Closet departure time is 2:00 PM,arriving at 4:08 PM");
	}
	else if(input_minutes<(15*60+45+19*60)/2){
		printf("Closet departure time is 3:45 PM,arriving at 5:55 PM");
	}
	else if(input_minutes<(19*60+21*60+45)/2){
		printf("Closet departure time is 7:00 PM,arriving at 9:20 PM");
	}
	else printf("Closet departure time is 9:45 PM,arriving at 11:58 PM");

return 0;
}
