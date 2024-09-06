#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


#define MAX 100

char Month[][12] = 
{"January","February","March","April",
  "May","June","July", "August","September",
  "October","November","December"};

int main(void){
  int month, day, year; 

  printf("Enter a date (mm/dd/yyyy):  ");
  scanf("%d/%d/%d",&month,&day,&year);
  printf("You entered the date %s %d, %d",Month[month-1],day,year);
  return 0;
}
