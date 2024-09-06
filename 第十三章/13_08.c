#include <stdio.h>
int compute_scrabble_value(const char *word);

int main(void){
  char words[100];

  printf("Enter a word: ");
  scanf("%s",words);
  printf("Scrabble value: %d", compute_scrabble_value(words));
  return 0;
}

int compute_scrabble_value(const char *word){
  int i = 0;
  char c = *(word + i++);
  int sum = 0;

  while(c != '\0') {
    c = toupper(c);
    if(c == 'D' || c =='G') sum+=2;
    else if(c == 'J' || c =='X')sum+=8;
    else if(c == 'Q' || c =='Z')sum+=10;
    else if(c == 'K')sum+=5;
    else if(c == 'B' || c =='C'|| c =='M'|| c =='P')sum+=3;
    else if(c == 'F' || c =='H'|| c =='V'|| c =='W'|| c =='Y')sum+=4;
    else sum+=1;
	c = *(word + i++);
  }
  return sum;
}
