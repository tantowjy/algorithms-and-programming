// Program menghitung deret kelipatan 3 sebanyak n-baris

#include <stdio.h>
int main() {
    int p, i, n, a;
    p = 3;
    i = 1, a = 0;
    printf("N baris : ");
    scanf("%d", &n);
    do {            //(A)Tentukan sintaksnya
        a = a + p;  //(B). Tentukan variabel
        p += 3;     //(C). Tentukan variabel
        i++;
    } while (i <= n);  //(D). Tentukan sintaksnya
    printf("Jumlah deretnya adalah %d", a);
}
