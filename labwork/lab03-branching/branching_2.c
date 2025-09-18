// Program Form Pinjam Buku
#include <stdio.h>
#include <stdlib.h>
int main() {
    int pil;
    char nama[50], waktu[20];
    printf("\t\tForm Pinjam Buku\n");
    printf(
        "List Buku\n1. Calculus 1 \n2. Sejarah Indonesia\n3. Ensiklopedia\n4. "
        "Rangkaian Listrik\n Pilihan : ");
    scanf("%d", &pil);
    getchar();
    switch (pil)  //(A). Tentukan variable switch
    {
        case 1:
            printf("\nNama Peminjam : ");
            gets(nama);
            printf("Lama Peminjaman: ");
            gets(waktu);
            printf("\nSelamat Menikmati ;)");
            break;  //(B). Tentukan sintaks pemberhenti
        case 2:
            printf("\nNama Peminjam : ");
            gets(nama);
            printf("Lama Peminjaman :");
            gets(waktu);
            printf("\nSelamat Menikmati ;)");
            break;
        case 3:
            printf("\nNama Peminjam : ");
            gets(nama);
            printf("Lama Peminjaman: ");
            gets(waktu);
            printf("\nSelamat Menikmati ;)");
            break;
        case 4:
            printf("\nNama Peminjam : ");
            gets(nama);
            printf("Lama Peminjaman: ");
            gets(waktu);
            printf("\nSelamat Menikmati ;)");
            break;
        default:  //(C). Tentukan sintaks
            printf("\nBuku tidak tersedia :(");
    }
    return 0;
}
