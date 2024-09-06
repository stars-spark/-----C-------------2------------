#include <stdio.h>
struct {
	int departure;
	int arriving;
} flight[] = {
	{0,0},{480,616},{583,712},{679,811},{767,900},
	{840,968},{945,1075},{1140,1280},{1305,1438} };
int main(void){
  int  i, hour, minute;
  int input_minutes;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &minute);
  input_minutes = hour*60+minute;
  for(i = 0; i < 8;i++){
  		if(input_minutes > flight[i].departure 
  				&& input_minutes < flight[i+1].departure) break;
  	}
  	if(i == 0 && flight[i+1].departure - input_minutes < input_minutes + 135)
  		printf("Closet departure time is %d:%d PM,arriving at %d:%d PM",
  		flight[i+1].departure/60,flight[i+1].departure%60,
  		flight[i+1].arriving/60,flight[i+1].arriving%60);
  	else
  		printf("Closet departure time is %d:%d PM,arriving at %d:%d PM",
  		flight[8].departure/60,flight[8].departure%60,
  		flight[8].arriving/60,flight[8].arriving%60);

  	if(input_minutes - flight[i].departure 
  		 < flight[i+1].departure - input_minutes)
  	printf("Closet departure time is %d:%d PM,arriving at %d:%d PM",
  		flight[i].departure/60,flight[i].departure%60,
  		flight[i].arriving/60,flight[i].arriving%60);
  	else 
	printf("Closet departure time is %d:%d PM,arriving at %d:%d PM",
  		flight[i+1].departure/60,flight[i+1].departure%60,
  		flight[i+1].arriving/60,flight[i+1].arriving%60);
	return 0;
}

