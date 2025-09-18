#include <stdio.h>

struct Peserta {
    char Nama[50], TTL[50], Gender[20], Lokasi[50];
    float BB;
} psrt;

void main() {
    printf("===INPUT===\n");
    printf("Nama : ");
    gets(psrt.Nama);
    printf("TTL : ");
    gets(psrt.TTL);
    printf("Jenis Kelamin : ");
    gets(psrt.Gender);
    printf("Berat Badan : ");
    gets(psrt.BB);
    printf("Lokasi Vaksin : ");
    gets(psrt.Lokasi);
    printf("===OUTPUT===\n");
    printf("Nama : %s \n", psrt.Nama);
    printf("TTL : %s \n", psrt.TTL);
    printf("Jenis Kelamin : %s \n", psrt.Gender);
    printf("Berat Badan : %f \n", psrt.BB);
    printf("Lokasi Vaksin : %s \n", psrt.Lokasi);
}
