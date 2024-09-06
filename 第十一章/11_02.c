#include <stdio.h>
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);
int main(void){
  int  departure, arrive;
  int input_minutes;
  int hour, minute;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &minute);
  input_minutes = hour*60+minute;
  find_closest_flight(input_minutes,&departure,&arrive);
  printf("%d",departure);
 return 0;
}
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time){
	if (desired_time<(615)/2){
        *departure_time = 21*60+45;
        *arrival_time = 24*60-2;
	}
	else if(desired_time<(8*60+9*60+43)/2){
		*departure_time = 8*60;
        *arrival_time = 10*60+16;
	}
	else if(desired_time<(9*60+43+11*60+19)/2){
        *departure_time = 9*60+43;
        *arrival_time = 11*60+52;
	}
	else if(desired_time<(11*60+19+12*60+47)/2){
        *departure_time = 11*60+19;
        *arrival_time = 13*60+31;
	}
	else if(desired_time<(12*60+47+14*60)/2){
        *departure_time = 12*60+47;
        *arrival_time = 15*60;
	}
	else if(desired_time<(14*60+15*60+45)/2){
        *departure_time = 14*60;
        *arrival_time = 16*60+8;
	}
	else if(desired_time<(15*60+45+19*60)/2){
        *departure_time = 15*60+45;
        *arrival_time = 17*60+55;
	}
	else if(desired_time<(19*60+21*60+45)/2){
        *departure_time = 19*60;
        *arrival_time = 21*60+20;
	}
	else {
        *departure_time = 21*60+45;
        *arrival_time = 24*60-2;
    }
}
