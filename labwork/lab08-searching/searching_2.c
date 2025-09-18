// Program searching data mahasiswa berdasarkan nama
#include <stdio.h>
#include <string.h>
int main() {
    struct {
        char nama[50], nim[50], kelas[50], jurusan[50];
    } a[50];
    int i, n, found = 0;
    char cari[50];
    // Proses input data
    printf("Jumlah input data : ");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        printf("%d. Nama\t\t: ", i + 1);
        gets(a[i].nama);
        printf(" NIM\t\t: ");
        gets(a[i].nim);
        printf(" Kelas\t\t: ");
        gets(a[i].kelas);
        printf(" Jurusan\t: ");
        gets(a[i].jurusan);
    }
    printf("\n");
    // Proses searching
    printf("Nama yang dicari : ");
    gets(cari);  //(A). Lengkapi variabel untuk kata yang dicari
    i = 0;
    found = 0;
    while (i < n) {
        if (strcmp(cari, a[i].nama) ==
            0)  // Lengkapi (B). variabel yang akan dibandingkan dan (C).
                // operasi boolean-nya
        {
            printf("Index ke-%d :\n", i + 1);
            printf(" Nama\t\t: %s\n", a[i].nama);
            printf(" NIM\t\t: %s\n", a[i].nim);
            printf(" Kelas\t\t: %s\n", a[i].kelas);
            printf(" Jurusan\t: %s\n\n", a[i].jurusan);
            found = 1;
        }
        i++;
    }
    if (found == 0) printf("\nData tidak ditemukan");
}
