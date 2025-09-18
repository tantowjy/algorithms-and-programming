#include <stdio.h>

int main() {
    int i, j, k, n;

    printf("Masukkan N = ");
    scanf("%d", &n);

    for (i = 1; i < n; i++) {
        for (j = 1; j <= n - 1; j++) {
            printf(".");
        }
        printf("%d", 2 * n - i);
        for (j = 1; j <= n - 1; j++) {
            printf(".");
        }
        printf("\n");
    }

    for (i = 1; i <= 2 * n - 1; i++) {
        printf("%d", i);
    }
    printf("\n");

    for (i = n; i > 1; i--) {
        for (j = 1; j <= n - 1; j++) {
            printf(".");
        }
        printf("%d", i - 1);
        for (j = 1; j <= n - 1; j++) {
            printf(".");
        }
        printf("\n");
    }

    return 0;
}
