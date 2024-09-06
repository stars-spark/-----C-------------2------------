#include <complex.h>
#include <stdio.h>
#include <math.h>

int main(void){ 
  double a, b, c;

  printf("Enter the  Coefficients a, b and c:");
  scanf("%lf %lf %lf",&a,&b,&c);
  double discriminant = b*b - 4*a*c;
  if(discriminant < 0){
	  double complex discriminant_sqrt = csqrt(b*b - 4*a*c);
	  double complex root1 =  (-b + discriminant_sqrt) / (2*a);
	  double complex root2 =  (-b - discriminant_sqrt) / (2*a);

	  if(cimag(root1) < 0)
		printf("root1 = %g - %gi\n", creal(root1),  fabs(cimag(root1)));
		//当复数根的虚部为负时，使用绝对值函数取绝对值，并手动添加负号
	  else printf("root1 = %g + %gi\n", creal(root1),  cimag(root1));
 
	  if(cimag(root2) < 0) 
		printf("root2 = %g - %gi\n", creal(root2),  fabs(cimag(root2)));
	  else printf("root2 = %g + %gi\n", creal(root2),  cimag(root2));
	  
	 }else{
		double discriminant_sqrt = sqrt(b * b-4 * a * c);
		double root1 = (-b + discriminant_sqrt) / (2 * a);
		double root2 = (-b - discriminant_sqrt) / (2 * a);
		printf("root1 = %g\n", root1);
		printf("root2 = %g\n", root2);
		}
   return 0;
}
