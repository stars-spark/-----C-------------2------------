#include <stdio.h>
int main(void){
	char words[30][20];
	char c;
	int pos = 0;
	int i = 0;

	printf("Enter a sentence: ");
	c = getchar();
	while(c != '.'&& c != '!' && c!='?'){
	  if(c != ' ')	  {
			words[pos][i++] = c;
	  }else{
			words[pos][i] = '\0';
			pos++;
			i = 0;
	  }
	  c = getchar();
	}

	printf("Reversal of sentence:");

	while(pos >= 0){
		printf("%s ",words[pos--]);
	}
	printf("%c",c);
		
	return 0;
}
