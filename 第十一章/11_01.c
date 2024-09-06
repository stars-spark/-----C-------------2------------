#include <stdio.h>
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);
int main(void){
    int amount;

    printf("Enter a dollar amount : ");
    scanf("%d",&amount);
    int twenty_note, ten_note, five_note, one_note;
    pay_amount(amount,&twenty_note, &ten_note, &five_note, &one_note);
    printf("$20 bills: %d\n",twenty_note);
    printf("$10 bills: %d\n",ten_note);
    printf("$5 bills: %d\n",five_note);
    printf("$1 bills: %d\n",one_note);
    return 0;
}
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones){
    *twenties = dollars / 20;
    *tens = (dollars - *twenties * 20) / 10;
    *fives = (dollars - *twenties * 20 - *tens * 10) / 5;
    *ones = (dollars - *twenties * 20 - *tens * 10) % 5;
}
