//stack.h
#include <stdbool.h>
#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

#endif
