#include <stdio.h>
#define PI 3.14f
int main(void){
    int radius;
    printf("Please Input the radius of the ball: ");
    scanf("%d",&radius);
    int radius3 = radius * radius * radius;
    float volume = 4.0f/3.0f * PI * radius3;
    printf("The Volume of ball is %f cubic metre",volume);
   return 0;
}
