#include <stdio.h>

int matrix[20][20];

void main() {
    int i, j, n;
    printf("Program Transpose Matriks\n\n");
    printf("n : ");
    scanf("%d", &n);
    // Input Element
    printf("\nInput Element:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Elemen baris %d kolom %d : ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    // Matrix
    printf("\nMatrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d \t", matrix[i][j]);
        }
        printf("\n\n");
    }
    // Transpose Matrix
    printf("\nTranspose Matrix:\n");
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            printf("%d \t", matrix[i][j]);
        }
        printf("\n\n");
    }
}
