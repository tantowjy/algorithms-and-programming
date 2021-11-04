//Membuat matriks A 2x2 dengan adjoin

#include <stdio.h>

int i,j,matriks[2][2];

void main(){
	printf("Input Matriks A : \n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("A[%d][%d] : ", i+1, j+1);
			scanf("%d", &matriks[i][j]);
		}
	}
	printf("\n\n==== Matriks A ====\n\n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("\t %d", matriks[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\n==== Adj(A) ====\n\n");
	printf("\t %d\t -%d", matriks[1][1], matriks[0][1]);
	printf("\n\n");
	printf("\t -%d\t %d", matriks[1][0], matriks[0][0]);
}
