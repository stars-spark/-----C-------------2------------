#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  struct tm t;
  int n;

  t.tm_sec = 0;
  t.tm_min = 0;
  t.tm_hour = 0;
  t.tm_isdst = -1;

  printf("Enter the date (M/D/Y):");
  scanf("%d/%d/%d",&t.tm_mon,&t.tm_mday,&t.tm_year);
  t.tm_year -= 1900;
  t.tm_mon -= 1;
  printf("Enter the date after :");
  scanf("%d",&n);
  t.tm_mday += n;
  mktime(&t);
  printf("That day is: %d/%d/%d \n",t.tm_mon + 1,t.tm_mday,t.tm_year+1900);
  puts(asctime(&t));
  return 0;
}
