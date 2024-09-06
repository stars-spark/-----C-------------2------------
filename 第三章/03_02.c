#include <stdio.h>

int main(void){
  int number;
  float price;
  int day, month, year;

  printf("Enter item number: ");
  scanf("%d",&number);
  
  printf("Enter unit price: ");
  scanf("%f",&price);
  
  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%d / %d / %d", &month, &day, &year);

  printf("Item\t\tUnit\t\tPurchase\n");
  printf("\t\tPrice\t\tdate\n");

  printf("%-d\t\t$%7.2f\t%-02d/%-02d/%-04d",number,price,month,day,year);
  return 0;
}	
