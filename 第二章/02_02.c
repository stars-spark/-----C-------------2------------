#include <stdio.h>
#define PI 3.14f
int main(void){
    int radius = 10;
    int radius3 = radius * radius * radius;
    float volume = 4.0f / 3.0f * PI * radius3;
    printf("The Volume of ball is %f cubic metre.",volume);
   return 0;
}
