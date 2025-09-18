#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mahasiswa {
    char nama[30], nim[20], nilai[20];
} mhs[20];

int x, y, a = 1, b = 1;
void input(int m, int p);
void output(int n, int q);

int main() {
    printf("=== INPUT ===\n");
    printf("Jumlah mahasiswa : ");
    scanf("%d", &x);
    y = x;
    getchar();
    input(x, a);
    printf("\n=== OUTPUT ===\n");
    output(y, b);
    return 0;
}

void input(int m, int p) {
    if (m > 0) {
        printf("%d. ", p);
        printf("Nama : ");
        gets(mhs[p].nama);
        printf(" NIM : ");
        gets(mhs[p].nim);
        printf(" Nilai : ");
        gets(mhs[p].nilai);
        input(m - 1, p + 1);
    }
}

void output(int n, int q) {
    if (n > 0) {
        printf("%d. ", q);
        printf("Nama : %s \n", mhs[q].nama);
        printf(" NIM : %s \n", mhs[q].nim);
        printf(" Nilai : %s \n", mhs[q].nilai);
        output(n - 1, q + 1);
    }
}
