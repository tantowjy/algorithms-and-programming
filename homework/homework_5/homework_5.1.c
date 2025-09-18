#include <stdio.h>

int n, i, j, k, a[100], ax[100], min, temp, sum;

void main() {
    printf("=== HW5.1 ===\n");
    printf("Input number of element : ");
    scanf("%d", &n);
    printf("Enter element : \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // first sorting
    for (i = 0; i <= n - 1; i++) {
        temp = a[i];
        j = i;
        while ((j > 0) && (temp < a[j - 1])) {
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = temp;
    }
    // find the minimum value of 2 numbers
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (a[i] < a[j]) {
                ax[i] = a[i];
            } else {
                ax[i] = a[j];
            }
        }
    }
    // second sorting
    for (i = 0; i <= n - 1; i++) {
        temp = ax[i];
        j = i;
        while ((j > 0) && (temp < ax[j - 1])) {
            ax[j] = ax[j - 1];
            j = j - 1;
        }
        ax[j] = temp;
    }
    // max sum
    sum = 0;
    for (i = 0; i < (n / 2) - 1; i++) {
        sum += ax[i * 2];
    }
    sum += ax[n - 1];
    // output
    printf("Maximum sum : %d \n", sum);
}
