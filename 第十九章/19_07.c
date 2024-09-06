#include <stdio.h>
#include <stdlib.h>
#include “queue.h”

typedef int Item;

typedef struct node{
  unsigned long Item;
  struct node* pnext;
}Node;

struct queue_type{
  Node* phead;
  Node* ptail;
  int amount;
};

typedef struct queue_type *Queue;

Queue create(void);
void add(Queue s, Item n);
Item remove(Queue s);
bool is_empty(const Queue s);
void make_empty(Queue s);
bool is_full(const Queue s);
void destroy(Queue s);


static void terminate(const char *message){
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Queue create(void){
  Queue s = malloc(sizeof(struct queue_type));
  if (s == NULL)
    terminate("Error in create: queue could not be created.");
  s->phead = s->ptail = NULL;
  s->amount = 0;
  return s;
}

void destroy(Queue s){
  make_empty(s);
  free(s);
}

void make_empty(Queue s){
  if(!is_empty(s)) remove(s);
}

bool is_empty(Queue s){
  return s->amount == 0;
}

bool is_full(Queue s){
	return false;
}

void add(Queue s, Item n){
  Node* pnode = malloc(sizeof(Node));
  if(pnode == NULL)
	terminate("Error in malloc new node.");
  pnode->Item = n;
  pnode->pnext = NULL;
  if (is_empty(s)){
	s->ptail = s->phead = pnode;
	s->amount++;
	}else{
	  s->ptail->pnext = pnode;
	  s->ptail = pnode;
	  s->amount++;
	  }
}

Item remove(Queue s){
  if (is_empty(s))
    terminate("Error in Remove: Queue is empty.");
  Node* pnode = s->phead;
  Item n;
  s->phead = s->phead->pnext;
  s->amount--;
  n = pnode->Item;
  free(pnode);
  return n;
}

