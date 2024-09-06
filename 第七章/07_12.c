#include <stdio.h>

int main(void)
{
  char operate;
  float number,result=0;
  printf("Enter an expression: ");
  scanf("%f",&result);
//读取第一个操作数
 while((operate = getchar())!='\n'){
//读取运算符，如果是回车符则退出循环
   scanf("%f",&number);
//读取第下一个操作数
    if(operate == '+') result+=number;
    else if(operate == '-') result -= number;
    else if(operate == '*') result *= number;
    else if(operate == '/') result /= number;
  }
  printf("Value of expression: %f\n",result);
  return 0;
}
