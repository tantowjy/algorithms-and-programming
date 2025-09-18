#include <stdio.h>
#include <string.h>

struct DaftarNilai {
    char nama[50];
    int nilai;
} a[100];

char temp[50];
int i, j, n, max;

void main() {
    printf("===INPUT===\n");
    printf("Banyak data : ");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        printf("%d. Nama : ", i + 1);
        gets(a[i].nama);
        printf("Nilai : ");
        scanf("%d", &a[i].nilai);
        getchar();
    }
    for (i = 0; i < n; i++) {
        max = i;
        for (j = i; j < n; j++) {
            if (a[max].nilai < a[j].nilai) {
                max = j;
            }
        }
        strcpy(temp, a[max].nama);
        strcpy(a[max].nama, a[i].nama);
        strcpy(a[i].nama, temp);
    }
    printf("===OUTPUT===\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s \n", i + 1, a[i].nama);
    }
}
