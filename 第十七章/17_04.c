#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef LINE_H
#define LINE_H

/**********************************************************
 * clear_line: Clears the current line.                   *
 **********************************************************/
void clear_line(void);

/**********************************************************
 * add_word: Adds word to the end of the current line.    *
 *           If this is not the first word on the line,   *
 *           puts one space before word.                  *
 **********************************************************/
void add_word(const char *word);

/**********************************************************
 * space_remaining: Returns the number of characters left *
 *                  in the current line.                  *
 **********************************************************/
int space_remaining(void);

/**********************************************************
 * write_line: Writes the current line with               *
 *             justification.                             *
 **********************************************************/
void write_line(void);

/**********************************************************
 * flush_line: Writes the current line without            *
 *             justification. If the line is empty, does  *
 *             nothing.                                   *
 **********************************************************/
void flush_line(void);

#endif


#define MAX_LINE_LEN 60
struct word_node
{
  char word[20];
  struct word_node* pnext;
};

struct word_node* line = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  for(int i = num_words - 1 ;i >= 0 ;i--)
    free((line+i));
  line  = NULL;
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  struct word_node* pline = line;
  struct word_node* p = malloc(sizeof( struct word_node));
  if(p == NULL)
  {
    printf("Error int malloc new word.\n");
    exit(EXIT_FAILURE);
  }
  line_len += strlen(word);
  strcpy(p->word, word);
  p->pnext = NULL;
  while(pline->pnext != NULL) pline = p->pnext;
  pline->pnext = p;
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, i, j;

  extra_spaces = MAX_LINE_LEN - line_len;
  for (i = 0; i < num_words; i++) {
    puts((line + i)->word);
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
  }
  putchar('\n');
}

void flush_line(void)
{
  if (line_len > 0){
    for (int i = 0; i < num_words; i++) {
    puts((line + i)->word);
    }
  }
}
