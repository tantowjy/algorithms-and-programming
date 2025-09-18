// Binary Search
#include <stdio.h>
int main() {
    int a[10] = {25, 6, 51, 2, 32, 90, 1, 5, 7, 63};
    int i, j, idx, temp, max, min, mid, cari;
    // Proses sorting
    for (i = 0; i < 10 - 1; i++) {
        for (j = 0; j < 10 - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    // Proses searching
    printf("\nAngka yang dicari : ");
    scanf("%d", &cari);
    idx = -1;
    min = 0;  //(A). Tentukan nilai untuk min
    max = 9;  //(B). Tentukan nilai untuk max
    while (min <= max && idx == -1) {
        mid = (min + max) / 2;  //(C). Tentukan rumus untuk mencari mid
        if (a[mid] == cari) {
            idx = mid;
        } else if (a[mid] > cari) {
            max = mid - 1;  //(D). Tentukan variabelnya
        } else
            min = mid + 1;
    }
    if (idx != -1)  //(E). Lengkapi operasi boolean jika data ditemukan
    {
        printf("Angka ditemukan pada indeks ke-%d", idx);
    } else
        printf("Angka tidak ditemukkan");
}
