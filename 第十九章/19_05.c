#include <stdio.h>
#include <stdlib.h>
#include “queue.h”

typedef int Item;

typedef struct queue_type *Queue;

Queue create(void);
void add(Queue s, Item n);
Item remove(Queue s);
bool is_empty(const Queue s);
bool is_full(const Queue s);
bool destroy(Queue s);

#define QUEUE_SIZE 100

struct queue_type{
  Item contents[QUEUE_SIZE];
  int head;
  int tail;
  int amount;
};


static void terminate(const char *message){
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Queue create(void){
  Queue s = malloc(sizeof(struct queue_type));
  if (s == NULL)
    terminate("Error in create: queue could not be created.");
  s->head = s->tail = s->amount = 0;
  return s;
}

void destroy(Queue s){
  make_empty(s);
  free(s);
}

void make_empty(Queue s){
  s->head = s->tail = s->amount = 0;
}

bool is_empty(Queue s){
  return s->amount == 0;
}

bool is_full(Queue s){
  	if(s->tail >= QUEUE_SIZE -1 || s->amount > =QUEUE_SIZE )
return true;
	   else return false;
}

void add(Queue s, Item n){
  if (is_full(s))
    terminate("Error in add: queue is full.");
  s->contents[++(s->tail)] = n;
  s->amount++;
}

Item remove(Queue s){
  if (is_empty(s))
    terminate("Error in remove: queue is empty.");
  Item n = s->contents[s->head];
  s->head++;
  s->amount--;
  return n;
}
