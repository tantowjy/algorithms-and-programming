#include <stdio.h>

int geometry(int x, int y);
int m, n;

int main() {
    printf(" BARISAN GEOMETRI \n");
    printf("Masukkan suku pertama : ");
    scanf("%d", &m);
    printf("Masukkan n-suku : ");
    scanf("%d", &n);
    printf("Output barisan : ");
    geometry(m, n);
    return 0;
}

int geometry(int x, int y) {
    if (y == 0) {
        return 0;
    } else if (y > 0) {
        printf("%d ", x);
        return geometry(x * 3, y - 1);
    }
}
