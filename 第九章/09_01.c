#include <stdio.h>

int selection_sort(int a[],int n){
	if(n == 0) return 0;
	int max, pos = 0;
	for(int i = 0 ;i < n; i++) if(a[pos]<a[i]) pos = i;
	max = a[pos];
	a[pos] = a[n-1];
	a[n-1] = max;
	return selection_sort(a,n-1);
}


int main(void){	
	int number[5];
	int i = 0;
	printf("Enter number to sort:");
	for(i = 0; i<5;i++) scanf("%d",&number[i]);
	for(i = 0; i<5;i++) printf("%3d",number[i]);
	selection_sort(number,5);
	printf("\nAfter sort: ");
	for(i = 0; i<5;i++) printf("%3d",number[i]);

	return 0 ;
}
