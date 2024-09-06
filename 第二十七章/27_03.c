#include <complex.h>
#include <stdio.h>
#include <math.h>

int main(void){ 
  double a, b ,r, q;

  printf("Enter the polar coord(in degree):");
  scanf("%lf %lf",&r,&q);
  
  double complex comp = r*cos(q/180*3.14) + r*sin(q/180*3.14)*I;
  printf("The complex coord is (%lf,%lf)",creal(comp),cimag(comp));
  return 0;
}
