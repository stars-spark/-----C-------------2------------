#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH  1000000L

long int DATA[MAX_LENGTH];
long int bigger(long int *pn, long int *pm);
long int smaller(long int *pn, long int *pm); 

int main(void){

  srand((unsigned)time(NULL));
  for(int i = 0 ;i < MAX_LENGTH; i++)
	DATA[i] = rand()%MAX_LENGTH;
  qsort(DATA,MAX_LENGTH,sizeof(int),bigger);

  clock_t start_clock = clock();
  qsort(DATA,MAX_LENGTH,sizeof(int),smaller);
  printf("\nProcessor time used: %g sec.\n",
         (clock() - start_clock) / (double) CLOCKS_PER_SEC);
}

long int bigger(long int *pn, long int *pm){
  return *pn-*pm;
  }
long int smaller(long int *pn, long int *pm)  {
	return *pm-*pn;
	}
