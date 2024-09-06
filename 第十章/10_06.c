#include <stdbool.h>    /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

int main(void){
  char ch;
  int result;
  int input, first, second;
  printf("Enter an RPN expression: ");
  scanf("%c",&ch);
  while(ch != '\n'){
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
      else if(ch == '/'){
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


void make_empty(void){
  top = 0;
}

bool is_empty(void){
  return top == 0;
}

bool is_full(void){
  return top == STACK_SIZE;
}

void push(int i){
  if (is_full()){
    printf("Expression is too complex\n");
    exit(0);
  }
  else
    contents[top++]  = i;
}

int pop(void){
  if (is_empty())  {
    printf("Not enough operands in expression\n");
    exit(0);
  }
  else
    return contents [--top];
}

