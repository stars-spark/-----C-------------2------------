#include <stdio.h>
#include <time.h>
void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void){
	char map[10][10];
	generate_random_walk(map);
	print_array(map);

	return 0;
}

void generate_random_walk(char walk[10][10]){
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
				walk[i][j] = '.';

	char visited = 'A';
	int currentX,currentY;
	int direct[4] = {0,0,0,0};
	srand((unsigned int)time(NULL));
	int x;
	currentX = currentY = 0;
	walk[currentX][currentY] = visited++;

	while(1){
		int sum = direct[0]+direct[1]+direct[2]+direct[3];
		if(visited > 'Z' || sum == 4) break;
		x = rand()%4;	
		if(x == 0){
			if(currentY==0 ||walk[currentX][currentY-1] != '.' ){
				direct[0]  = 1;
				continue;
			}else{
				walk[currentX][--currentY] = visited++;
				direct[0]=direct[1]=direct[2]=direct[3]=0;
			} 
			
		}else if(x == 1){
			if(currentX==9 ||walk[currentX+1][currentY] != '.' ){
				direct[1]  = 1;
				continue;
			}else{
				walk[++currentX][currentY] = visited++;
				direct[0] = direct[1]=direct[2]=direct[3]=0;
				}
		}else if(x == 2){
			if(currentY==9 ||walk[currentX][currentY+1] != '.' ){
				direct[2]  = 1;
				continue;
				} 
			else{
				walk[currentX][++currentY] = visited++;
				direct[0] = direct[1]=direct[2]=direct[3]=0;
				}
		}else if(x == 3){
			if(currentX==0 ||walk[currentX-1][currentY] != '.' ){
				direct[3]  = 1;
				continue;
			}else{
				walk[--currentX][currentY] = visited++;
				direct[0] = direct[1]=direct[2]=direct[3]=0;
				}
			}
	}

}
void print_array(char walk[10][10]){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++)
				printf(" %c ",walk[i][j]);
			printf("\n");
		}
}
