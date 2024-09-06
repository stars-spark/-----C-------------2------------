#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50	/* maximum number of reminders */
#define MSG_LEN 60	/* max length of reminder message */

int read_line(char str[], int n);

int main(void){
  char reminders[MAX_REMIND][MSG_LEN+3];
  char msg_str[MSG_LEN+1];
  int month,day, i, j, num_remind = 0;
  int hour,minute;
  char time_str[12];

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day and reminder: ");
    scanf("%2d/%2d", &month,&day);
	scanf("%2d:%2d", &hour,&minute);
    if (day == 0)  break;
	if(day < 0 || day > 31)	{
	  printf("\nIgnore.\n");
	  while(getchar()!='\n');
	  continue;
	  }	
	
	sprintf(time_str, "%2d/%2d %2d:%2d",month,day,hour,minute);

    read_line(msg_str, MSG_LEN);
    for (i = 0; i < num_remind; i++)
      if (strcmp(time_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j-1]);

    strcpy(reminders[i], time_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

  return 0;
}

int read_line(char str[], int n){
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}

