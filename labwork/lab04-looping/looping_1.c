// Program deret bilangan lipat 3
#include <stdio.h>
main() {
    int i, n, a;
    i = 1;
    a = 3;
    printf("Masukan N baris : ");
    scanf("%d", &n);
    while (i <= n) {  //(A). Tentukan variabelnya
        printf("%d ", a);
        a = a + 3;  //(B). Tentukan variabelnya
        i++;        //(C). Tentukan operasinya
    }
}
