#include <stdio.h>

int arr[100];
int i, j, n, x, temp, low, high, idx, mid;

void main() {
    printf("===INPUT===\n");
    printf("Banyak Angka : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Angka %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Angka yang dicari : ");
    scanf("%d", &x);
    printf("===OUTPUT===\n");
    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            if (arr[j - 1] > arr[j]) {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Angka yang telah terurut : ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    low = 0;
    high = n - 1;
    idx = -1;
    while ((low <= high) && (idx == -1)) {
        mid = (low + high) / 2;
        if (arr[mid] == x) {
            idx = mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (idx != -1) {
        printf("Angka %d ditemukan pada urutan %d", x, idx + 1);
    } else {
        printf("Angka %d tidak ditemukan", x);
    }
}
