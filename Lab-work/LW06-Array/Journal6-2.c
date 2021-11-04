//Program Determinan Matriks 3x3
#include <stdio.h>
#include <stdlib.h>
int main(){
    int i, j, Det, matriks[3][3]; //(A). Lengkapi ukuran array

//INPUT
    printf("Masukkan angka: \n");
    for(i=0 ; i<=2 ; i++){
        for(j=0 ; j<=2 ; j++){
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%d", &matriks[i][j]); //(B). Tentukan variabel 
        }
    }
   printf("\n\n");

//OUTPUT MATRIKS 3x3 
    printf("\n---MATRIKS A---\n\n");

    for(i=0 ; i<=2 ; i++){
        for(j=0 ; j<=2; j++){ //(C). Tentukan operasi 
            printf("    %d", matriks[i][j]);
        }
        printf("\n\n");
    } 

//PROSES HITUNG DETERMINAN
Det=matriks[0][0]*matriks[1][1]*matriks[2][2]+matriks[0][1]*matriks[1][2]*matriks[2][0]+matriks[0][2]*matriks[1][0]*matriks[2][1];
Det=Det-(matriks[0][2]*matriks[1][1]*matriks[2][0]+matriks[0][1]*matriks[1][0]*matriks[2][2]+matriks[0][0]*matriks[1][2]*matriks[2][1]);
//OUTPUT Det(M)
	printf("\n\nDet(A) = %d",Det); //(D). Lengkapi variabel 
    return 0;         
}

