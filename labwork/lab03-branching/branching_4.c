#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    float c, f, r;
    printf("Suhu (C) = ");
    scanf("%f", &c);
    printf("Menu Konversi : \n");
    printf("1. Reamur\n");
    printf("2. Farenheit\n");
    printf("Pilih : ");
    scanf("%d", &i);

    switch (i) {
        case 1:
            r = c * 4 / 5;
            printf("Hasil Konversi : %.2f R", r);
            break;
        case 2:
            f = (c * 9 / 5) + 32;
            printf("Hasil konversi : %.2f F", f);
            break;
        default:
            printf("Menu tidak tersedia");
            break;
    }

    return 0;
}
