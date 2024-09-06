#include <stdbool.h>    /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

int evaluate_RPN_expression(const char *expression);

/* external variables */
int contents[STACK_SIZE];
int top = 0;
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
int read_line(char str[], int n);

int main(void){
  char exp[50];

  printf("Enter an RPN expression: ");
  read_line(exp,50);
  printf("Result: %d",evaluate_RPN_expression(exp));
  return 0;
}

int evaluate_RPN_expression(const char *expression){
  char ch = *expression;
  int i = 0;
  int result = 0;
  int input, first, second;

  while(ch != '\n')  {
     if((ch-'0')>=0 &&(ch-'9'<=0)){
       input = ch - '0';
			i++;
			ch = *(expression + i);
       while((ch-'0')>=0 &&(ch-'9'<=0)){
         input = input*10 + ch - '0';
		  		i++;
		  		ch = *(expression + i);
        }
        push(input);
        continue;
      }
      else if(ch == '+') push(pop()+pop());
      else if(ch == '*') push(pop()*pop());
      else if(ch == '-'){
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
          return result;
        }else{
          printf("Error!");
          return 0;
        }
      }
	  i++;
      ch = *(expression + i);
  }
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
  if (is_full())  {
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

int read_line(char str[], int n){
  int ch, i = 0;

  while ((ch = getchar()) != '\n' && ch != EOF)
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
