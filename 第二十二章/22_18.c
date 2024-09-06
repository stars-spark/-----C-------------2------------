#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(int argc, char *argv[]){
  FILE *fp;
  char ch;
  int number[MAX];
  int length = 0;
  if (argc != 2) {
    fprintf(stderr, "usage: calc file\n");
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf (stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while((fscanf(fp," %d",&number[length++])) != EOF);
  length--;
  quicksort(number,0,length - 1);
  printf("The Min = %d, Max = %d,",number[0],number[length-1]);
  printf(" and the Mid = %d \n",length%2==1?number[length/2]:(number[length/2-1]+number[length/2]) /2 );
  fclose(fp);
  return 0;
}

void quicksort(int a[], int low, int high){
  int middle;

  if (low >= high) return;
  middle = split(a, low, high);
  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high){
  int part_element = a[low];

  for (;;) {
    while (low < high && part_element <= a[high])
      high--;
    if (low >= high) break;
    a[low++] = a[high];

    while (low < high && a[low] <= part_element)
      low++;
    if (low >= high) break;
    a[high--] = a[low];
  }

  a[high] = part_element;
  return high;
}
