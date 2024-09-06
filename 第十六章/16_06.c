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

#include <stdio.h>
struct date{
  int month;
  int day;
  int year;
  }d1 ,d2;

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(void){
  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);

  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);
  	if(compare_dates(d1,d2) == -1) 
    	printf("%d/%d/%02d is earlier than %d/%d/%02d", 
                d1.month, d1.day, d1.year,d2.month, d2.day, d2.year);
  	else if(compare_dates(d1,d2) == 1)
    	printf("%d/%d/%02d is earlier than %d/%d/%02d",
             d2.month, d2.day, d2.year,d1.month, d1.day, d1.year);
	else  printf("%d/%d/%02d is equal  %d/%d/%02d",
             d1.month, d1.day, d1.year,d2.month, d2.day, d2.year);
return 0;
}

int compare_dates(struct date d1, struct date d2)  {
  	if (d1.year < d2.year) return -1;
		else if(d1.year > d2.year) return 1;
		else if(d1.year == d2.year && day_of_year(d1) < day_of_year(d1))
			return -1;
		else if(d1.year == d2.year && day_of_year(d1) > day_of_year(d1))
			return 1;
		else return 0;
	}

int day_of_year(struct date d)  {
	int total = 0;
  	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

  	for(int i  = 0; i< d.month - 1; i++) total += months[i];
  	total += d.day;
  if((d.year%4 ==0 && d.year%100 != 0)||(d.year%400 == 0) )  {
    if(d.month > 2) total++;//闰年且月份大于2，则补1天。
  }
  return total;
}
