#include <stdio.h>

int main(void){
  int hour, minute;
  int input_minutes;
  char am_pm;
  printf("Enter a 12-hour time: ");
  scanf("%d:%d %c", &hour, &minute,&am_pm);
  if(am_pm == 'A' || am_pm == 'a') 
  	 printf("Equivalent 24-hour time: %d:%d",hour,minute);
  else 
  	printf("Equivalent 24-hour time: %d:%d",hour+12,minute);
 return 0;
}
