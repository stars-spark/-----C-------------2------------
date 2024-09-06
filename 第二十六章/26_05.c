#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  struct tm t;
  int n;
  time_t t0,t1;
  
  t.tm_sec = 0;
  t.tm_min = 0;
  t.tm_hour = 0;
  t.tm_isdst = -1;

  printf("Enter the date (M/D/Y):");
  scanf("%d/%d/%d",&t.tm_mon,&t.tm_mday,&t.tm_year);
  t.tm_year -= 1900;
  t.tm_mon -= 1;
  t0 = mktime(&t);
  printf("Enter the date (M/D/Y):");
  scanf("%d/%d/%d",&t.tm_mon,&t.tm_mday,&t.tm_year);
  t.tm_year -= 1900;
  t.tm_mon -= 1;
  t1 = mktime(&t);

  printf("That day betweens is : %.0f \n",difftime(t1,t0)/86400);
  puts(asctime(&t));
  return 0;
}
