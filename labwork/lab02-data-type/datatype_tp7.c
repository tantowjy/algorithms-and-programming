#include <stdio.h>

struct Peserta {
    char Nama[40], TTL[40], JK[40], BB[40], Lokasi[40];
} p;

void main() {
    printf("===INPUT===\n");
    printf("Nama          : ");
    gets(p.Nama);
    printf("TTL           : ");
    gets(p.TTL);
    printf("Jenis Kelamin : ");
    gets(p.JK);
    printf("Berat Badan   : ");
    gets(p.BB);
    printf("Lokasi Vaksin : ");
    gets(p.Lokasi);
    printf("===OUTPUT===\n");
    printf("Nama          : %s \n", p.Nama);
    printf("TTL           : %s \n", p.TTL);
    printf("Jenis Kelamin : %s \n", p.JK);
    printf("Berat Badan   : %s \n", p.BB);
    printf("Lokasi Vaksin : %s \n", p.Lokasi);
}
