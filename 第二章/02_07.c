#include <stdio.h>
int main(void){
    int amount;
    printf("Enter a dollar amount : ");
    scanf("%d",&amount);
    int twenty_note = amount / 20;
    int ten_note = (amount - twenty_note * 20) / 10;
    int five_note = (amount - twenty_note * 20 - ten_note * 10) / 5;
    int one_note = (amount - twenty_note * 20 - ten_note * 10) % 5;
    printf("$20 bills: %d\n",twenty_note);
    printf("$10 bills: %d\n",ten_note);
    printf("$5 bills: %d\n",five_note);
    printf("$1 bills: %d\n",one_note);
    return 0;
}
