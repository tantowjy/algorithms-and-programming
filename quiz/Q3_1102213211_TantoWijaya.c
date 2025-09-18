#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("Masukkan n : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        for (j = n - i; j >= 1; j--) {
            printf("..");
        }
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
