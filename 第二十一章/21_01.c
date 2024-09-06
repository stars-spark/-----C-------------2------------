#include <stdio.h>
#include <stdlib.h>

struct stest{
  char a;
  int b;
  double c;
  } s;

int main(int argc, char *argv[]){

  printf("SIZEOF S = %lu\n", sizeof(s));
  printf("SIZEOF S.A = %lu\n", sizeof(s.a));
  printf("OFFSETOF S.A = %lu\n", offsetof(struct stest, a));
  printf("SIZEOF S.B = %lu\n", sizeof(s.b));
  printf("OFFSETOF S.B = %lu\n", offsetof(struct stest, b));
  printf("SIZEOF S.C = %lu\n", sizeof(s.c));
  printf("OFFSETOF S.C = %lu\n", offsetof(struct stest, c));

  return 0;
}
