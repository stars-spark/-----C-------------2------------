#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(void){
  char smallest_word[20], largest_word[20], temp[20];

  printf("Enter word: ");
  scanf("%s",temp);
  strcpy(smallest_word,temp);
  while(strlen(temp) != 4)
  {
    if(strcmp(smallest_word,temp) > 0) strcpy(smallest_word,temp);
    if(strcmp(largest_word,temp) < 0) strcpy(largest_word,temp);
    printf("Enter word: ");
    scanf("%s",temp);
  }
  printf("Smallest word : %s\n",smallest_word);
  printf("Largest word: %s\n",largest_word);
return 0;
}
