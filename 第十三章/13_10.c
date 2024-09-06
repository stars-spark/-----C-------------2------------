#include <stdio.h>
#include <string.h>
void reverse_name(char *name);
int read_line(char str[], int n);

int main(void){
  char name[100];

  printf("Enter a first and last name: ");
  read_line(name,100);
  reverse_name(name);
  printf("%s\n",name);
  return 0;
}

void reverse_name(char *name){
  char fname[2];
  char lname[strlen(name)];
  char* p = name;

  while(*p++ ==' ') 
  		fname[0] = *p;
  while(*p++ !=' ');
  strcpy(lname,p);
  strcpy(name,lname);
  strcat(name,".");
  strcat(name,fname);
  }

int read_line(char str[], int n){
  int ch, i = 0;

  while ((ch = getchar()) != '\n' && ch != EOF)
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
  }
