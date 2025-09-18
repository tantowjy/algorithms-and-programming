#include <stdio.h>

int main() {
    FILE *f_biner;
    FILE *f_biner2;
    char cari[30];
    int n, i;
    struct {
        char nama[30], nim[30], angkatan[5];
        float ipk;
    } mhs;

    printf("===INPUT===\n");
    f_biner = fopen("Mahasiswa.dat", "rb");
    f_biner2 = fopen("Mahasiswa2.dat", "wb");
    printf("Masukan nama yang datanya ingin dihapus : ");
    gets(cari);
    while (fread(&mhs, sizeof(mhs), 1, f_biner) == 1) {
        if (strcmp(mhs.nama, cari) != 0) {
            fwrite(&mhs, sizeof(mhs), 1, f_biner2);
        }
    }
    fclose(f_biner);
    fclose(f_biner2);

    remove("Mahasiswa.dat");
    rename("Mahasiswa2.dat", "Mahasiswa.dat");

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
