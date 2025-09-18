#include <stdio.h>
#include <stdlib.h>
#define phi 3.14

struct {
    char Name[50], Address[50], Phone[20];
    float d, L;
} data;

int main() {
    printf("Nama = ");
    gets(data.Name);
    printf("Alamat = ");
    gets(data.Address);
    printf("Nomor Telepon = ");
    gets(data.Phone);
    printf("Diameter Bolu = ");
    scanf("%f", &data.d);
    data.L = (phi * data.d * data.d) / 4;
    printf("Nama = %s \n", data.Name);
    printf("Alamat = %s \n", data.Address);
    printf("Nomor Telepon = %s \n", data.Phone);
    printf("Diameter Bolu = %.0f cm \n", data.d);
    printf("Luas Bolu = %.2f cm^2 \n", data.L);
    return 0;
}
