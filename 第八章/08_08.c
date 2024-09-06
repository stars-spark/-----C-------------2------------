#include <stdio.h>

int main(void){
	int scores[5][5];
	float stu_sum;
	float cour_sum, cour_max, cour_min;
	for(int i = 0; i < 5; i++){
		printf("Enter Student %d's scores: ", i+1);
		for(int j = 0; j < 5; j++){
			scanf("%d",&scores[i][j]);
		}
		getchar();
	}
	printf("Student: \tNo.1\t\tNo.2\t\tNo.3\t\tNo.4\t\tNo.5\n");
	printf("Sum#Average:\t");
	for(int i = 0; i < 5; i++){
	  stu_sum = 0;
	  for(int j = 0; j < 5; j++){
		stu_sum += scores[i][j];
	  }
	printf("%.1f#%.1f\t", stu_sum,stu_sum/5);
	}
	
	printf("\nCourse: \tNo.1\t\tNo.2\t\tNo.3\t\tNo.4\t\tNo.5\n");
	printf("Avg#Max#Min:\t");
	for(int i = 0; i < 5; i++){
	  cour_sum = cour_max = cour_min = scores[0][i];
	  for(int j = 0; j < 5; j++){
		  cour_sum += scores[j][i];
		  if(cour_max<scores[j][i]) cour_max = scores[j][i];
		  if(cour_min>scores[j][i]) cour_min = scores[j][i];
	  }
	printf("%.1f#%.1f#%.1f\t", cour_sum/5,cour_max,cour_min);
	}
  
	return 0;
}
