#include <stdio.h>
int main(void){
	char sentence[100];
	char ch;
	int i, pos = 0;
	sentence[0] = ' '; //首字符设定为空格，便于逆序的判断
	printf("Enter a sentence: ");
	ch = getchar();
	while(ch != '.'&& ch != '!' && ch !='?'){
		sentence[++pos] = ch;
		ch = getchar();
	}

	printf("Reversal of sentence:");

	while(pos > 0){
		i = pos;
		while(pos >= 0 && sentence[pos--] != ' ');
			for(int k = pos+1; k <= i ; k++)
				printf("%c",sentence[k]);
	}
	printf("%c",ch);
		
	return 0;
}
