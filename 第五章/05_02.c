#include <stdio.h>

int main(void){
	int hour = 0, minute = 0;
	printf("Enter a 24-hour time:");
	scanf("%d:%d",&hour,&minute);
	if(hour>12 && hour <=24)//判断是否是24小时的下午
		printf("Equivalent 12-hour time: %d:%02d PM",
               hour%12 ,minute);
	else //否则就是24小时的上午
		printf("Equivalent 12-hour time: %d:%02d AM", 
                hour, minute);
 return 0;
}
