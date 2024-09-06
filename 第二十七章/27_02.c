#include <complex.h>
#include <stdio.h>
#include <math.h>

int main(void){ 
  double a, b ,r, q;
  printf("Enter the complex coord:");
  scanf("%lf %lf",&a,&b);
  double complex comp = a + b*I;
  r = sqrt(a*a + b*b);
  q = carg(comp)*180/3.14;
  printf("The polar coord is (%lf,%lf)",r,q);
  return 0;
}
