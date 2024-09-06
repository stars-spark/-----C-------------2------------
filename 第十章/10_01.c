#include <stdbool.h>    /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;

void make_empty(void){
  top = 0;
}

bool is_empty(void){
  return top == 0;
}

bool is_full(void){
  return top == STACK_SIZE;
}

void stack_overflow(void){
  printf("Stack overflow\n");
}

void stack_underflow(void){
  printf("Stack underflow\n");
  exit(EXIT_FAILURE);
}

void push(char i){
  if (is_full())
    stack_overflow();
  else
    contents[top++]  = i;
}

char pop(void){
  if (is_empty())
    stack_underflow();
  else
    return contents [--top];
}

int main(){
  int ch;
  printf("Enter parenteses and/or braces:");
  while((ch=getchar())!='\n'){
    if(ch == '('||ch == '{') push(ch);
    else if(ch == ')'){
      if(!is_empty() || pop() !='('){
        printf("Parenteses/braces are not nested properly\n");
        break;
        }  
    }else if(ch == '}'){
      if(!is_empty() || pop() !='{'){
        printf("Parenteses/braces are not nested properly\n");
        break;
        }   
    }
  }
  if(is_empty()) printf("Parenteses/braces are nested properly\n");
  make_empty();
  return 0;
}
