#include <stdio.h>
#include <stdlib.h>
#include “queue.h”

typedef int Item;

typedef struct queue_type *Queue;

Queue create(int size);
void add(Queue s, Item n);
Item remove(Queue s);
bool is_empty(const Queue s);
bool is_full(const Queue s);
bool destroy(Queue s);

#define QUEUE_SIZE 100

struct queue_type{
  Item *contents;
  int head;
  int tail;
  int amount;
  int size;
} ;


static void terminate(const char *message){
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Queue create(int size){
  Queue s = malloc(sizeof(struct queue_type));
  if (s == NULL)
    terminate("Error in create: queue could not be created.");
  s->contents = malloc(size * sizeof(Item));
  if (s->contents == NULL) {
    free(s);
    terminate("Error in create: queue could not be created.");
  }
  s->size = size;
  s->head = s->tail = s->amount = 0;
  return s;
}

void destroy(Queue s){
  make_empty(s);
  free(s->contents);
  free(s);
}

void make_empty(Queue s){
  s->head = s->tail = s->amount = 0;
}

bool is_empty(Queue s){
  return s->amount == 0;
}

bool is_full(Queue s){
  	if(s->tail >= s->size - 1 || s->amount > = s->size )
		  return true;
	else return false;
}

void add(Queue s, Item n){
  if (is_full(s))
    terminate("Error in add: Queue is full.");
  s->contents[++(s->tail)] = n;
  s->amount++;
}

Item remove(Queue s){
  if (is_empty(s))
    terminate("Error in remove: Queue is empty.");
  Item n = s->contents[s->head];
  s->head++;
  return n;
}
