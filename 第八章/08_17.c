#include <stdio.h>
int main(void){
	int n;	
	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d",&n);
	int magic[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0 ;j <n; j++)magic[i][j] = 0;
		}

	int x = 0, y = n/2;
	
	for(int k = 1; k <= n*n; k++){
		if(magic[x][y] != 0){
			x = (x + 2 + n) % n;
			y = (--y + n) %n;
			magic[x][y] = k;
			}
		else magic[x][y] = k;
		x = (--x + n) % n;
		y = (++y + n) % n;

		}
		
	for(int i = 0; i < n; i++){
		for(int j = 0 ;j <n; j++)
			printf("%d\t",magic[i][j]);
		printf("\n");
		}
	return 0;
}

