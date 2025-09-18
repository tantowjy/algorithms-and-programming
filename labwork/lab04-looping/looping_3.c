#include <stdio.h>

int main() {
    int n, x = 0, i = 1;

    printf("Banyak Baris = ");
    scanf("%d", &n);

    while (i <= n) {
        x += 2;
        i++;
        printf("%d ", x);
    }

    return 0;
}
