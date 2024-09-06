#include <stdio.h>

int main(void){
  int num1, num2, num3, num4;
  int max1, max2, min1, min2;
  printf("Enter four integers : ");
  scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

  if(num1 > num2 ){ 	//比较前两个数的大小关系
  	max1 = num1; min1 = num2;
  }else{
  	max1 = num2; min1 = num1;
  }

   if(num3 > num4 ){ 	//比较后两个数的大小关系
  	max2 = num3; min2 = num4;
  }else{
  	max2 = num4; min2 = num3;
  }
	printf("Largest: %d\n",max1>max2?max1:max2);
	//比较前两个较大数之间的大小关系
	printf("Smallest: %d\n",min1<min2?min1:min2);
	//比较前两个较小数之间的大小关系
return 0;
}
