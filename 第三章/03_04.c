#include <stdio.h>

int main(void){
  int first, second, third;

  printf("Enter phone number [(xxx) xxx-xxxx]: ");
  scanf("(%d)%d-%d",&first,&second,&third);
  //按照确定格式读取用户输入的电话号码
  printf("You entered  %03d.%03d.%04d\n",first,second,third);
  return 0;
}	

