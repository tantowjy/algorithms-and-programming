#include <stdio.h>
struct {
    char name[50], bentuk[50];
    int harga;
} a;
int i, n;
void main() {
    FILE *pesanan;
    FILE *pesanan2;
    char dicari[50];
    pesanan = fopen("List Pesanan.dat", "rb");
    pesanan2 = fopen("List Pesanan2.dat", "wb");
    printf("Silahkan masukkan nama menu yang akan dihapus: ");
    gets(dicari);
    while (fread(&a, sizeof(a), 1, pesanan) == 1) {
        if (strcmp(a.name, dicari) != 0) {
            fwrite(&a, sizeof(a), 1, pesanan2);
        }
    }

    fclose(pesanan);
    fclose(pesanan2);
    remove("List Pesanan.dat");
    rename("List Pesanan2.dat", "List Pesanan.dat");

    printf("------OUTPUT READING BINER-----\n\n");
    int i = 1;
    pesanan = fopen("List Pesanan.dat", "rb");  //(E). Tentukan mode nya
    while (fread(&a, sizeof(a), 1, pesanan) ==
           1)  // Tentukan (F). sintaks dan (G). variabel read biner
    {
        printf("%d.\tNama Pemesan\t: %s\n", i, a.name);
        printf("\tBentuk bolu\t: %s\n", a.bentuk);
        printf("\tHarga\t\t: %d\n\n", a.harga);
        i++;
    }
    fclose(pesanan);
}
