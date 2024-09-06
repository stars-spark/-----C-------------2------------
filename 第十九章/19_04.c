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

void push(Stack s, void *p){
  struct node *new_node = malloc(sizeof(struct node));	
  if (new_node == NULL)
    terminate("Error in push: stack is full.");

  new_node->data = p;
  new_node->next = s->top;
  s->top = new_node;
}

void *pop(Stack s){
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
  Stack s1, s2;
  char* n;

  s1 = create();
  s2 = create();

  push(s1, "Hello");
  push(s1, "World");
  n = pop(s1);
  printf("Popped %s from s1\n", n);
  push(s2, n);
  n = pop(s1);
  printf("Popped %s from s1\n",n);
  push(s2, n);

  destroy(s1);

  while (!is_empty(s2))
    printf("Popped %s from s2\n", pop(s2));

  push(s2,3);
  make_empty(s2);
  if (is_empty(s2))
    printf("s2 is empty\n");
  else
    printf("s2 is not empty\n");

  destroy(s2);

  return 0;
}
