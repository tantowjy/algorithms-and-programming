#include <stdio.h>

int matrix1[20][20],matrix2[20][20],matrix[20][20];

int main(){
	int nr1,nc1,nr2,nc2,i,j,k,n, sum = 0;
	printf("Program Perkalian Matriks\n\n");
	// Input Element Matrix 1
	printf("Matriks 1\n");
	printf("jumlah baris : "); scanf("%d", &nr1);
	printf("jumlah kolom : "); scanf("%d", &nc1);
	for(i=0; i<nr1; i++){
		for(j=0; j<nc1; j++){
			printf("Elemen baris %d kolom %d : ", i+1, j+1);
			scanf("%d", &matrix1[i][j]);
		}
	}
	// Input Element Matrix 2
	printf("\nMatriks 2:\n");
	printf("jumlah baris : "); scanf("%d", &nr2);
	printf("jumlah kolom : "); scanf("%d", &nc2);
	if(nc1 != nr2){
		printf("Ordo Matriks tidak memenuhi");
		return 0;
	} else {
		for(i=0; i<nr2; i++){
			for(j=0; j<nc2; j++){
				printf("Elemen baris %d kolom %d : ", i+1, j+1);
				scanf("%d", &matrix2[i][j]);
			}
		}
	}
	
	// Perkalian Matrix
	for(i=0; i<nr1; i++){
		for(j=0; j<nc2; j++){
			for(k=0; k<nr2; k++){
				sum = sum + matrix1[i][k]*matrix2[k][j];
			}
			matrix[i][j] = sum;
			sum = 0;
		}
	}
	// Hasil Perkalian Matrix
	printf("\nHasil Perkalian Matriks 1 dan Matriks 2 :\n");
	for(i=0; i<nr1; i++){
		for(j=0; j<nc2; j++){
			printf("%d \t", matrix[i][j]);
		}
		printf("\n\n");
	}
	return 0;
}
