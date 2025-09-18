#include <stdio.h>

int main() {
    // deklarasi variabel
    float a, b;

    // input
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);

    // output
    printf("Hasil dari a/b adalah %.2f", a / b);

    return 0;
}
