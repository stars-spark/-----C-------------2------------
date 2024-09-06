#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


#define MAX 100

bool is_palindrome(const char *message);
int main(void){
  char str[MAX];
  char ch;
  int i = 0;

  printf("Enter a message: ");
  while((ch = getchar())!='\n' && i < MAX)
    if(isalpha(ch)) str[i++] = ch;
  if(is_palindrome(str))
    printf("Palindrome.\n");
  else  printf("Not a palindrome.\n");

  return 0;
}

bool is_palindrome(const char *message){
  int i = 0;
  int n = strlen(message);
  while( i < n/2){
    if(toupper(*(message+i)) != toupper(*(message+n-1-i)))
      return false;
    i++;
  }
  return true;
}
