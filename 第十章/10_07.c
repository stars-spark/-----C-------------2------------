#include <stdbool.h>    /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#define MAX_DIGITS 10
/* external variables */

const int segments[10][7] =
{{1, 1, 1, 1, 1, 1, 0},//0
{0, 1, 1, 0, 0, 0, 0},//1
{1, 1, 0, 1, 1, 0, 1},//2
{1, 1, 1, 1, 0, 0, 1},//3
{0, 1, 1, 0, 0, 1, 1},//4
{1, 0, 1, 1, 0, 1, 1},//5
{1, 0, 1, 1, 1, 1, 1},//6
{1, 1, 1, 0, 0, 0, 0},//7
{1, 1, 1, 1, 1, 1, 1},//8
{1, 1, 1, 1, 0, 1, 1},//9
};

char digits[3][MAX_DIGITS*4];
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void){
  char ch;
  int pos = 0;
  clear_digits_array();
  printf("Enter a number: ");
  while((ch=getchar())!='\n'){
    if(pos>=MAX_DIGITS) break;
    if(ch-'0'>=0&&ch-'9'<=0){
      process_digit(ch-'0',pos++);
    }
  }
  print_digits_array();
  return 0;
}
void clear_digits_array(void){
  for(int i = 0; i < 3; i ++)
    for(int j = 0; j < MAX_DIGITS*4 ;j++)
      digits[i][j] = ' ';
}
void process_digit(int digit, int position){
    if(segments[digit][5] == 1) digits[0][position * 4] = '|';
      else digits[0][position * 4] = ' ';
    if(segments[digit][4] == 1) digits[2][position * 4] = '|';
      else digits[2][position * 4] = ' ';

    if(segments[digit][0] == 1) digits[0][position * 4 + 1] = '-';
      else digits[0][position * 4 + 1] = ' ';
    if(segments[digit][6] == 1) digits[1][position * 4 + 1] = '-';
      else digits[1][position * 4 + 1] = ' ';
    if(segments[digit][3] == 1) digits[2][position * 4 + 1] = '_';
      else digits[2][position * 4 + 1] = ' ';

    if(segments[digit][1] == 1) digits[0][position * 4 + 2] = '|';
      else digits[0][position * 4 + 2] = ' ';
    if(segments[digit][2] == 1) digits[2][position * 4 + 2] = '|';
      else digits[2][position * 4 + 2] = ' ';

}
void print_digits_array(void){
  for(int i = 0; i < 3; i ++){
    for(int j = 0; j < MAX_DIGITS*4 ;j++)
    {
        printf("%c",digits[i][j]);
    }
    printf("\n");
  }
}
