//Program writing dan reading biner untuk pendataan pesanan
#include <stdio.h>
struct
{
    char name[50], bentuk[50];
    int harga;
} a;
int i, n;
void main()
{
    FILE *pesanan;
    pesanan = fopen("List Pesanan.dat", "ab"); //(A). Tentukan modenya 
    printf("Banyak pesanan : ");
    scanf("%d", &n);
    getchar();
    for (i = 1; i <= n; i++)
    {
        printf("%d.\tNama Pemesan\t: ", i);
        gets(a.name);
        printf("\tBentuk bolu\t: ");
        gets(a.bentuk);
        printf("\tHarga\t \t: ");
        scanf("%d", &a.harga);
        getchar();
        fwrite (&a, sizeof(a), 1, pesanan); //Tentukan (B). sintaks  dan (C). lengkapi 
    }
    fclose(pesanan); //(D). Lengkapi sintaksnya

 printf("------OUTPUT READING BINER-----\n\n");
    int i = 1;
    pesanan = fopen("List Pesanan.dat", "rb"); //(E). Tentukan mode nya
    while (fread(&a, sizeof(a), 1, pesanan) == 1) // Tentukan (F). sintaks dan (G). variabel read biner
    {
        printf("%d.\tNama Pemesan\t: %s\n", i, a.name);
        printf("\tBentuk bolu\t: %s\n", a.bentuk);
        printf("\tHarga\t\t: %d\n\n", a.harga);
        i++;
    }
    fclose(pesanan);
}
