#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 50    /* maximum number of reminders */
#define WORD_LEN 20     /* max length of remider message */
int read_line(char str[], int n);

int main()
{
  char *word_list[MAX_WORD];
  char  input[WORD_LEN];
  int count = 0;
  printf("Enter word: ");
  read_line(input, WORD_LEN);
  while(strlen(input) > 0)
  {
    word_list[count] = malloc((strlen(input)+1)*sizeof(char));
    if(word_list[count] == NULL) break;
    strcpy(word_list[count],input);
    printf("Enter word: ");
    read_line(input, WORD_LEN);
    count++;
  }
  
  char* temp;
  for(int i = 0; i < count;i++){
    for(int j = 0; j < count - 1;j++){
      if(strcmp(word_list[j],word_list[j+1])>0){
        temp = word_list[j];
        word_list[j] = word_list[j+1];
        word_list[j+1] = temp;
      }
    }
  }

  for(int i = 0; i < count;i++)
    puts(word_list[i]);
  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
