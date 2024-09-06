#include <stdio.h>
#include <time.h>

int main(void){
  time_t current = time(NULL);
  char date_time[100];
  
  struct tm *ptr;
  int hour;
  char am_or_pm;  
  ptr = localtime(&current);
  hour = ptr->tm_hour;
  
  strftime(date_time, sizeof(date_time),
           "%A, %B %d, %Y %I:%M", localtime(&current));
  
  if (hour <= 11)
    strcat(date_time,"a\n");
  else {
    strcat(date_time,"p\n");
  }

  puts(date_time);
 
    strftime(date_time, sizeof(date_time),
           "%a, %d %b %y   %H:%M\n", localtime(&current));
  puts(date_time);

    strftime(date_time, sizeof(date_time),
           "%m/%d/%y  %I:%M:%S %p\n", localtime(&current));
  puts(date_time);

  return 0;
}


