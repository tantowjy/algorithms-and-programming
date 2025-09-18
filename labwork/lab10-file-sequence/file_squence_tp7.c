#include <stdio.h>

int main() {
    FILE *f_biner;
    int n, i;
    struct {
        char nama[30], nim[30], angkatan[5];
        float ipk;
    } mhs;

    printf("===INPUT===\n");
    f_biner = fopen("Mahasiswa.dat", "wb");
    printf("Banyak Mahasiswa : ");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        printf("%d. Nama : ", i + 1);
        gets(mhs.nama);
        printf(" NIM : ");
        gets(mhs.nim);
        printf(" Angkatan : ");
        gets(mhs.angkatan);
        printf(" IPK (x.xx) : ");
        scanf("%f", &mhs.ipk);
        getchar();
        fwrite(&mhs, sizeof(mhs), 1, f_biner);
    }
    fclose(f_biner);

    printf("\n===OUTPUT===\n");
    f_biner = fopen("Mahasiswa.dat", "rb");
    i = 0;
    while (fread(&mhs, sizeof(mhs), 1, f_biner) == 1) {
        i++;
        printf("%d. Nama : %s \n", i, mhs.nama);
        printf(" NIM : %s \n", mhs.nim);
        printf(" Angkatan : %s \n", mhs.angkatan);
        printf(" IPK : %.2f \n", mhs.ipk);
    }
    fclose(f_biner);

    return 0;
}
