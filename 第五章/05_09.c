#include <stdio.h>

int main(void){
  int  fm, fd, fy; //存储输入的第一个日期信息
  int  sm, sd, sy; //存储输入的第二个日期信息

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &fm, &fd, &fy);

  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &sm, &sd, &sy);
  if(fy > sy ||(fy == sy && fm >sm) 
    ||(fy == sy && fm == sm && fd > sd)) 
    printf("%d/%d/%02d is earlier than %d/%d/%02d", 
              sm, sd, sy, fm, fd, fy);
  else 
    printf("%d/%d/%02d is earlier than %d/%d/%02d",
              fm, fd, fy, sm, sd, sy);
   
return 0;
}
