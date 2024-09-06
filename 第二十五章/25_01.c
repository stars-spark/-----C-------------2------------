#include <stdio.h>
#include <locale.h>

int main(void){
  char* str =  setlocale(LC_CTYPE, "C");
  printf("%s\n",str);
 
  str =  setlocale( LC_CTYPE, "" );
  printf("%s\n",str);
}
