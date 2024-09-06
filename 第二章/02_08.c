#include <stdio.h>
int main(void){
    float loan, rate, mpayment;
    printf("Enter amount of loan : ");
    scanf("%f",&loan);
    printf("Enter interest rate : ");
    scanf("%f",&rate);
    printf("Enter monthly payment : ");
    scanf("%f",&mpayment);

    float mrate = rate/1200;
    float remain_1 = loan + loan * mrate -mpayment;
    float remain_2 = remain_1 + remain_1 * mrate -mpayment;
    float remain_3 = remain_2 + remain_2 * mrate -mpayment;

    printf("Balance remaining after first paymen: $%.2f\n",remain_1);
    printf("Balance remaining after second paymen: $%.2f\n",remain_2);
    printf("Balance remaining after third paymen: $%.2f\n",remain_3);

    return 0;
}
