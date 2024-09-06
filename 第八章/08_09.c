#include <stdio.h>
#include <time.h>

int main(void){
	char map[10][10];
	char visited = 'A';
	int currentX,currentY;
	int direct[4] = {0,0,0,0};
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++) map[i][j] = '.';
	}

	srand((unsigned) time(NULL));
	int x;
	currentX = currentY = 0;
	map[currentX][currentY] = visited++;
	
	while(1){
		int sum = direct[0]+direct[1]+direct[2]+direct[3];
		if(visited > 'Z' || sum == 4) break;
		x = rand()%4;	
		if(x == 0){
			if(currentY==0 ||map[currentX][currentY-1] != '.' ){
				direct[0]  = 1;
				continue;
			}else{
				map[currentX][--currentY] = visited++;
				direct[0]=direct[1]=direct[2]=direct[3]=0;
			} 
			
		}else if(x == 1){
			if(currentX==9 ||map[currentX+1][currentY] != '.' ){
				direct[1]  = 1;
				continue;
			}else{
				map[++currentX][currentY] = visited++;
				direct[0] = direct[1]=direct[2]=direct[3]=0;
				}
		}else if(x == 2){
			if(currentY==9 ||map[currentX][currentY+1] != '.' ){
				direct[2]  = 1;
				continue;
				} 
			else{
				map[currentX][++currentY] = visited++;
				direct[0] = direct[1]=direct[2]=direct[3]=0;
				}
		}else if(x == 3){
			if(currentX==0 ||map[currentX-1][currentY] != '.' ){
				direct[3]  = 1;
				continue;
			}else{
				map[--currentX][currentY] = visited++;
				direct[0] = direct[1]=direct[2]=direct[3]=0;
				}
			}
	}
	printf("\n");
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf(" %c ",map[i][j]);
		}
		printf("\n");
	}

	return 0;
}
