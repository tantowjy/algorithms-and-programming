#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mahasiswa {
    char nama[50], nim[50];
} p[50];

char cari[50];
int i, n;

void main() {
    printf("===INPUT===\n");
    printf("Banyak mahasiswa : ");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        printf("%d. Nama : ", i + 1);
        gets(p[i].nama);
        printf(" NIM : ");
        gets(p[i].nim);
    }
    printf("Nama mahasiswa yang dicari : ");
    gets(cari);
    printf("===OUTPUT===\n");
    for (i = 0; i < n; i++) {
        if (strcmp(cari, p[i].nama) == 0) {
            printf("%s dengan NIM %s ada diurutan %d", p[i].nama, p[i].nim,
                   i + 1);
            break;
        } else if (i == n - 1) {
            printf("Nama mahasiswa tidak ditemukan!");
        }
    }
}
