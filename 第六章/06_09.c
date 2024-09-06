#include <stdio.h>
int main(void){
    float loan, rate, mpayment,times, mrate, remain;
    printf("Enter amount of loan : ");
    scanf("%f",&loan);
    printf("Enter interest rate : ");
    scanf("%f",&rate);
    printf("Enter monthly payment : ");
    scanf("%f",&mpayment);
    printf("Enter payment month: ");
    scanf("%f",&times);
	mrate = rate/1200;
	remain = loan;
	for(int i = 0; i < times; i++){
		remain = remain + remain * mrate - mpayment;
		printf("Balance remaining after %d paymen: $%.2f\n",i+1,remain);
	}

    return 0;
}
