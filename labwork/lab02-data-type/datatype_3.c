#include <stdio.h>
#define phi 3.14
#define price 200

int main() {
    float d, luas, TPrice;
    printf("Diameter (cm) bolu : ");
    scanf("%f", &d);
    luas = 0.25 * phi * d * d;
    TPrice = luas * price;
    printf("Harga Bolu = Rp%.0f", TPrice);
    return 0;
}
