#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100


struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
} new_part, inventory[MAX_PARTS];

int num_parts = 0;   /* number of parts currently stored */

int main(int argc, char* argv[]){
  FILE* fp;
  char fname[20];
  int combile = 0;

  printf("Read File data...\n");
  printf("Enter the file name:");
  scanf("%s",fname);

  if((fp = fopen(fname,"r")) == NULL){
		printf("Cant't open file %s.", fname);
		return 0;
  }

  while(fscanf(fp,"%d#%s #%d\n", &inventory[num_parts].number,
           inventory[num_parts].name, &inventory[num_parts].on_hand) == 3)
	num_parts++;
  fclose(fp);

  printf("\nDone\nRead File data...\n");
  printf("Enter the file name:");
  scanf("%s",fname);

  if((fp = fopen(fname,"r")) == NULL){
		printf("Cant't open file %s.", fname);
		return 0;
  }

  while(fscanf(fp,"%d#%s #%d\n", &new_part.number,
           new_part.name, &new_part.on_hand) == 3){
		combile = 0;
		for(int i = num_parts-1; i >= 0 ;i--){
	  			if(inventory[i].number == new_part.number &&
		 				strcmp(new_part.name,inventory[i].name) == 0){
					inventory[i].on_hand += new_part.on_hand;
					combile = 1;
					break;
				}
	  	if(inventory[i].number == new_part.number && 
				strcmp(new_part.name,inventory[i].name) != 0) {
			printf("Error data. exit");
			exit(EXIT_FAILURE);
		}
	 }

	  if(combile == 1) continue;

	  for(int i = num_parts-1; i >= 0 ;i--){
	  		if(inventory[i].number > new_part.number) {
		  		inventory[i+1].number = inventory[i].number;
		  		strcpy(inventory[i+1].name ,inventory[i].name);
		  		inventory[i+1].on_hand = inventory[i].on_hand;
		  		inventory[i].number = new_part.number;
		  		strcpy(inventory[i].name, new_part.name);
		  		inventory[i].on_hand = new_part.on_hand;
			}
	  }
	  num_parts++;
  }
  
return 0;
}
