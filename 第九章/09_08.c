
/* Sums a series of numbers (using long int variables) */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
int roll_dice(void);
bool play_game(void);

int main(void){
	char ch;
	do{
		if(play_game()) printf("You win!\n");
			else printf("You lose!\n");
		printf("\nPlay again? ");
		ch=getchar();
		while(getchar()!='\n');
		}while(ch=='y');
	return 0;
}

int roll_dice(void){
	int i,j;
	srand((unsigned int)time(NULL));
	return (rand()%6 + 1)+(rand()%6 + 1);
}
bool play_game(void){
	int temp;
	int point = roll_dice();
	printf("You rolled: %d\n",point);
	if(point == 7||point ==11) return true;
	printf("You point is %d\n",point);
	while(1){
		temp = roll_dice();
		printf("You rolled: %d\n",temp);
		if(temp == point) return true;
		if(temp == 7) return false;
	}
}
