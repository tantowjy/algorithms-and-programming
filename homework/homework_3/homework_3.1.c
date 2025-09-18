#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int i, n, x = 0, y = 0, z;

    printf("Input integer : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            x = x + factorial(i);
            if (i < n) {
                printf("%d! - ", i);
            } else if (i = n) {
                printf("%d! = ", i);
            }
        } else if (i % 2 == 0) {
            y = y + factorial(i);
            if (i < n) {
                printf("%d! + ", i);
            } else if (i = n) {
                printf("%d! = ", i);
            }
        }
    }

    z = x - y;
    printf("%d \n", z);
}
