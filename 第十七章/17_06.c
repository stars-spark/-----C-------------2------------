#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 50    /* maximum number of reminders */
#define WORD_LEN 20     /* max length of remider message */
int read_line(char str[], int n);
int compare(const void *p, const void *q);

int main()
{
  char* word_list[MAX_WORD];
  char  input[WORD_LEN];
  int count = 0;
  printf("Enter word: ");
  read_line(input, WORD_LEN);
  while(strlen(input) > 0)
  {
    word_list[count] = malloc((strlen(input) + 1)*sizeof(char));
    strcpy(word_list[count],input);
    printf("Enter word: ");
    read_line(input, WORD_LEN);
    count++;
  }

  qsort(word_list,count,sizeof(word_list[0]),compare);

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
int compare(const void *p, const void *q)
{
 return strcmp(*((char**)p), *((char**)q));
}
