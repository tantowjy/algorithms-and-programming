#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mahasiswa {
    char nama[50], nim[20], meet[10], alasan[100];
} a[100];

int i, n;

void main() {
    printf("===INPUT===\n");
    printf("Jumlah Mahasiswa : ");
    scanf("%d", &n);
    getchar();
    for (i = 1; i <= n; i++) {
        printf("%d. Nama : ", i);
        gets(a[i].nama);
        printf("NIM : ");
        gets(a[i].nim);
        printf("Pertemuan ke : ");
        gets(a[i].meet);
        printf("Alasan : ");
        gets(a[i].alasan);
    }
    printf("===OUTPUT===\n");
    printf("Daftar absen Algoritma dan Pemrograman : \n");
    for (i = 1; i <= n; i++) {
        printf("%d. %s (%s) pada pertemuan ke-%s dengan alasan %s \n", i,
               a[i].nama, a[i].nim, a[i].meet, a[i].alasan);
    }
}
