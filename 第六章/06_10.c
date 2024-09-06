#include<stdio.h>

int main(void){
  int  month, day, year;
  int  early_month, early_day, early_year;
  printf("Enter a date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month, &day, &year);
  early_month = month;
  early_day = day;
  early_year = year;
  while(month !=0 || day != 0 || year != 0){
      if(year<early_year||
        (year == early_year && month < early_month) || 
        (year == early_year && month == early_month && day < early_day) ){
        early_month = month;
        early_day = day;
        early_year = year;
    }
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month, &day, &year);
  }
  printf("%2d/%2d/%2d is the earliest date", early_month, early_day, early_year );
 return 0;
}
