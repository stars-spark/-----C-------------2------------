#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
  FILE* fip, *fop;
  char fname[20];
  char message[80];
  char ch;
  int n;
  int length = 0;

  printf("Enter name of file to be encrypted:  ");
  scanf("%s",fname);

  if((fip = fopen(fname,"r")) == NULL)  {
	  printf("Cann't open file %s.",fname);
	  exit(EXIT_FAILURE);
  }
  strcat(fname,"enc");
  if((fop = fopen(fname,"w")) == NULL)  {
	  printf("Cann't open file %s.",fname);
	  exit(EXIT_FAILURE);
  }

	printf("Enter shift amount (1-25): ");
	scanf("%d",&n);

	while((ch = fgetc(fip)) != EOF) {
		if(ch>='a'&& ch<='z')
		ch = ((ch - 'a') + n) % 26 + 'a';
		else if(ch>='A'&& ch<='Z')
			ch = ((ch - 'A') + n) % 26 + 'A';
		fputc(ch,fop);
		}
	printf("All Done.");
	
	fclose(fip);
	fclose(fop);
	return 0;
}
