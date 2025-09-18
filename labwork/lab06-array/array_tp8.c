#include <stdio.h>
#include <stdlib.h>

int i, j, m, n, matrix1[50][50], matrix2[50][50];

void main() {
    printf("Jumlah baris : ");
    scanf("%d", &m);
    printf("Jumlah kolom : ");
    scanf("%d", &n);
    printf("\nMatriks 1 : \n");
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            printf("Isi baris %d, kolom %d : ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("\nMatriks 2 : \n");
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            printf("Isi baris %d, kolom %d : ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("\nHasil Penjumlahan Matriks 1 dan Matriks 2 : \n");
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d \t", matrix1[i][j] + matrix2[i][j]);
        }
        printf("\n\n");
    }
}
