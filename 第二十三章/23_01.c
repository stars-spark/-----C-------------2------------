#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
  int a ,b, c;
  double root1,root2;

  printf("Enter the a ,b ,c, of the ax*x+bx+c=0: ");
  scanf("%d %d %d",&a,&b,&c);
  double d = (b * b-4 * a * c);

  if(d < 0) printf("The root is Complex.\n");
  else{
	  root1 = (-b + sqrt(d))/(2*a);
	  root2 = (-b - sqrt(d))/(2*a);
	  printf("The root is %f and %f ",root1,root2);
	}
return 0;
}
