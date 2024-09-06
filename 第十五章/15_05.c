//prn.c
#include <stdio.h>
#include "stack.h"

int main(void){
  char ch;
  int result;
  int input, first, second;

  printf("Enter an RPN expression: ");
  scanf("%c",&ch);
  while(ch != '\n')  {
      if((ch-'0')>=0 &&(ch-'9'<=0)){
        input = ch - '0';
        scanf("%c",&ch);
        while((ch-'0')>=0 &&(ch-'9'<=0)){
          input = input*10 + ch - '0';
          scanf("%c",&ch);
        }
        push(input);
        continue;
      }
      else if(ch == '+') push(pop()+pop());
      else if(ch == '*') push(pop()*pop());
      else if(ch == '-') {
        second = pop();
        first = pop();
        push(first - second);
      }
      else if(ch == '/') {
        second = pop();
        first = pop();
        push(first / second);
      }else if(ch == '='){
        result = pop();
        if(is_empty()) {
          printf("Value of expression: %d" ,result);
          break;
        }else{
          printf("Error!");
          break;
        }
      }
      scanf("%c",&ch);
  }
  return 0;
}
