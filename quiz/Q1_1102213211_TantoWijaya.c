#include <stdio.h>

int main() {
    int n, i;

    printf("Input N = ");
    scanf("%d", &n);

    for (i = n; i >= 1; i--) {
        if (i != 1) {
            printf("Anak ayam turun %d, mati 1 tinggal %d \n", i, i - 1);
        } else {
            printf("Anak ayam turun %d, mati 1 tinggal induknya.\n", i);
        }
    }

    return 0;
}
