// fseek file sekuensial
#include <stdio.h>
int main() {
    FILE *data;
    int no_struct;
    long int offset_byte;

    struct {
        char name[50], bentuk[50];
        int harga;
    } a;

    data = fopen("List Pesanan.dat", "rb");
    printf("Silahkan masukkan nomor urutan yang ada pada menu: ");
    scanf("%d", &no_struct);                    //(A). Lengkapi variabel
    offset_byte = (no_struct - 1) * sizeof(a);  //(B). Lengkapi variabel
    fseek(data, offset_byte,
          SEEK_SET);  // Tentukan (C). sintaks dan (D). referensi whence

    if (fread(&a, sizeof(a), 1, data) == 0) {
        printf("Menu yang dicari tidak dapat ditemukan pada a.\n");
    } else {
        printf("Menu\t: %s\n", a.name);
        printf("Bentuk bolu\t: %s\n", a.bentuk);
        printf("Harga\t: %d", a.harga);
    }

    fclose(data);
    return 0;
}
