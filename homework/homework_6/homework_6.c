#include<stdio.h>

void main(){
	int i,j,x,y,tmp;
	printf("n x n binary matrix image\n");
	printf("n1 = "); scanf("%d", &x);
	printf("n2 = "); scanf("%d", &y);
	// Input binary matrix image
	int array[x][y];
	for(i=0; i<x; i++){
		for(j=0; j<y; j++){
			printf("a[%d][%d] = ", i+1, j+1);
			scanf("%d", (*(array+i)+j));
		}
	}
	// Print binary matrix image
	printf("\nInput: image = [");
	for(i=0; i<x; i++){
		printf("[");
		for(j=0; j<y; j++){
			if(j!=y-1){
				printf("%d,", *(*(array+i)+j));
			} else {
				printf("%d", *(*(array+i)+j));
			}
		}
		if(i!=x-1){
			printf("],");
		} else {
			printf("]");
		}
	}
	printf("]");
	// Flip Horizontal
	for(i=0; i<x; i++){
		for(j=0; j<y/2; j++){
			tmp = *(*(array+i)+j);
			*(*(array+i)+j) = *(*(array+i)+y-1-j);
			*(*(array+i)+y-1-j) = tmp;
		}
	}
	// Invert
	for(i=0; i<x; i++){
		for(j=0; j<y; j++){
			if(*(*(array+i)+j)==0){
				*(*(array+i)+j) = 1;
			} else {
				*(*(array+i)+j) = 0;
			}
		}
	}
	// print invert horizontal
	printf("\n\nOutput: [");
	for(i=0; i<x; i++){
		printf("[");
		for(j=0; j<y; j++){
			if(j!=y-1){
				printf("%d,", *(*(array+i)+j));
			} else {
				printf("%d", *(*(array+i)+j));
			}
		}
		if(i!=x-1){
			printf("],");
		} else {
			printf("]");
		}
	}
	printf("]");
}
