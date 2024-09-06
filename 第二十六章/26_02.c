#include <stdio.h>
#include <stdlib.h>

void call_all();
void call_folks();
  
int main(void){
  atexit(call_folks);
  atexit(call_all);
  return 0;
}

void call_all(){
  printf("That's all, ");
  }
void call_folks(){
  printf("folks!.");
}
