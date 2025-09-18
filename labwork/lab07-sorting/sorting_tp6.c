#include <stdio.h>

int a[100];
int i, j, n, max, temp;

void main() {
    printf("===INPUT===\n");
    printf("Jumlah data : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Data %d : ", i + 1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        max = i;
        for (j = i; j < n; j++) {
            if (a[max] < a[j]) {
                max = j;
            }
        }
        temp = a[max];
        a[max] = a[i];
        a[i] = temp;
    }
    printf("===OUTPUT===\nHasil Pengurutan : ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
