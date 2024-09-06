#include <stdio.h>
int main(void){
  char fname = ' ';
  char c;
  int lname = 0;
  printf("Enter a first and last name: ");
  while((c = getchar())!='\n'){
if(c != ' ' && fname == ' ') fname = c;
//确认读取First name 首字母
else if(c == ' ' && lname == 0) lname = 1;
//确认first name 输入完成，开始输入Last name
    else if(c != ' ' && lname == 1) printf("%c",c);
  }
  printf(", %c.",fname);
  //输出逗号和First name 首字母
  return 0;
}
