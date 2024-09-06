#include <stdio.h>
#include <math.h>
int main(void){
  double x ,newy, y = 1.0;
  printf("Enter a positive number: ");
  scanf("%lf",&x);
 do{
    newy = (y + x/y)/2;
    if( fabs(newy-y) < 0.00001*y ) break;
    else y = newy;
  }while(1);
  printf("Square root:: %f\n",y);
  return 0;
}
