//stack.c
#include <stdio.h>
#include <stdlib.h>
#include “stackadt.h”

#define STACK_SIZE 100

struct node {
  Item data;
  struct node *next;
};

struct stack_type {
  struct node *top;
};

static void terminate(const char *message){
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create(void){
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL)
    terminate("Error in create: stack could not be created.");
  s->top = NULL;
  return s;
}

void destroy(Stack s){
  make_empty(s);
  free(s);
}

void make_empty(Stack s){
  while (!is_empty(s))
    pop(s);
}

bool is_empty(Stack s){
  return s->top == NULL;
}

bool is_full(Stack s){
  return false;
}

void push(Stack s, Item i){
  struct node *new_node = malloc(sizeof(struct node));	
  if (new_node == NULL)
    terminate("Error in push: stack is full.");

  new_node->data = i;
  new_node->next = s->top;
  s->top = new_node;
}

Item pop(Stack s){
  struct node *old_top;
  Item i;
	
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");

  old_top = s->top;
  i = old_top->data;
  s->top = old_top->next;
  free(old_top);
  return i;
}

int main(void){

  char ch;
  int result;
  int input, first, second;

  Stack s = create();
  printf("Enter an RPN expression: ");
  scanf("%c",&ch);
  while(ch != '\n')
  {
      if((ch-'0')>=0 &&(ch-'9'<=0)){
        input = ch - '0';
        scanf("%c",&ch);
        while((ch-'0')>=0 &&(ch-'9'<=0)){
          input = input*10 + ch - '0';
          scanf("%c",&ch);
        }
        push(s,input);
        continue;
      }
      else if(ch == '+') push(s, pop(s)+pop(s));
      else if(ch == '*') push(s, pop(s)*pop(s));
      else if(ch == '-')
      {
        second = pop(s);
        first = pop(s);
        push(s, first - second);
      }
      else if(ch == '/')
      {
        second = pop(s);
        first = pop(s);
        push(s,first / second);
      }else if(ch == '='){
        result = pop(s);
        if(is_empty(s)) {
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
