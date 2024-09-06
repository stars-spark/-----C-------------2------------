/* Sums a series of numbers (using long int variables) */
#include <stdio.h>
void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

int main(void){
	int n;	
	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d",&n);
	int magic[n][n];
	create_magic_square(n,magic);
	print_magic_square(n,magic);
	return 0;
}

void create_magic_square(int n, char magic_square[n][n]){
	int x = 0, y = n/2;
	for(int i = 0; i < n; i++){
			for(int j = 0 ;j <n; j++) magic_square[i][j] = 0;
	}

	for(int k = 1; k <= n*n; k++){
		if(magic_square[x][y] != 0){
			x = (x + 2 + n) % n;
			y = (--y + n) %n;
			magic_square[x][y] = k;
			}
		else magic_square[x][y] = k;
		x = (--x + n) % n;
		y = (++y + n) % n;

		}

	
	}
void print_magic_square(int n, char magic_square[n][n]){
		for(int i = 0; i < n; i++){
			for(int j = 0 ;j <n; j++)
				printf("%d\t",magic_square[i][j]);
			printf("\n");
		}
}
