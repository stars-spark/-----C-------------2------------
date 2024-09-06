#include <stdio.h>

int main(void){
  int a[5][5];
  int rowsum,columnsum;
  for(int i = 0; i < 5; i++){
      printf("Enter row %d: ", i+1);
      for(int j = 0; j < 5; j++) 
        scanf("%d",&a[i][j]);
      getchar();//清除回车符号
  }
  printf("Row totals: ");
  for(int i = 0; i < 5; i++){
    rowsum = 0;
    for(int j = 0; j < 5; j++)
      rowsum += a[i][j];
    printf("%3d", rowsum);
  }

  printf("\nColumn totals: ");
  for(int i = 0; i < 5; i++){
    columnsum = 0;
    for(int j = 0; j < 5; j++)
      columnsum += a[j][i];
    printf("%3d", columnsum);
  }
  return 0;
}
