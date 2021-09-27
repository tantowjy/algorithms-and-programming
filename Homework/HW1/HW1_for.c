#include <stdio.h>
#include <string.h>

int main() {
    char* hari[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    char day[10];
    int n, i, index = -1;

    printf("Hari ini: ");
    scanf("%s", day);

    printf("Jumlah hari ke depan: ");
    scanf("%d", &n);

    // Cari indeks hari saat ini
    for (i = 0; i < 7; i++) {
        if (strcmp(day, hari[i]) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\n\n   =============================");
        printf("\n     !!PENULISAN HARI SALAH!!");
        printf("\n   =============================");
        printf("\n   Penulisan hari yang benar:");
        for (i = 0; i < 7; i++) {
            printf("\n   ==> %s", hari[i]);
        }
        printf("\n   =============================\n\n");
    } else {
        int hariBaru = (index + n) % 7;
        printf("%d hari setelah hari %s adalah %s\n", n, day, hari[hariBaru]);
    }

    return 0;
}
