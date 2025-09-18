#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nama[100][100], temp[100];
int i, j, n, max;

void main() {
    printf("===INPUT===\n");
    printf("Jumlah string : ");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        printf("String %d : ", i + 1);
        gets(nama[i]);
    }
    for (i = 0; i < n; i++) {
        max = i;
        for (j = i; j < n; j++) {
            if (strcmp(nama[max], nama[j]) > 0) {
                max = j;
            }
        }
        strcpy(temp, nama[max]);
        strcpy(nama[max], nama[i]);
        strcpy(nama[i], temp);
    }
    printf("===OUTPUT (poin A)===\nHasil Pengurutan : ");
    for (i = 0; i < n; i++) {
        printf("%s ", nama[i]);
    }
}
