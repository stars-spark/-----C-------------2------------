#include <stdio.h>

int main(void){
  int num1, num2, num3, num4, num5, num6, num7, num8, 
      num9, num10, num11, num12, num13, num14, num15, num16;

  printf("Enter the numbers from 1 to 16 in any order:\n");
  scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
         &num1,&num2,&num3,&num4,&num5,&num6,&num7,&num8,
         &num9,&num10,&num11,&num12,&num13,&num14,&num15,&num16);
  //读取用户输入的16个整数，并按照顺序保存至变量中。
  printf("%2d %2d %2d %2d \n",num1,num2,num3,num4);
  printf("%2d %2d %2d %2d \n",num5,num6,num7,num8);
  printf("%2d %2d %2d %2d \n",num9,num10,num11,num12);
  printf("%2d %2d %2d %2d \n",num13,num14,num15,num16);

  printf("Row sums: %d %d %d %d\n",
         (num1+num2+num3+num4),(num5+num6+num7+num8),
         (num9+num10+num11+num12),(num13+num14+num15+num16));
  //计算并输出四行的结果
  printf("Column sums: %d %d %d %d\n",
          (num1+num5+num9+num13),(num2+num6+num10+num14),
          (num3+num7+num11+num15),(num4+num8+num12+num16));
  //计算并输出四列的结果

  printf("Diagonal sums: %d %d\n",(num1+num6+num11+num16),(num4+num7+num10+num13));
  //计算并输出两个对角线的结果

  return 0;
}
