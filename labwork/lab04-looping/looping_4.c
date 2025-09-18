#include <stdio.h>

int main() {
    char city[20];
    int i;

    for (i = 1; i <= 3; i++) {
        if (i <= 3) {
            printf("Dimanakah ibu kota negara Indonesia : ");
            gets(city);
            if (strcmp(city, "Jakarta") == 0 || strcmp(city, "jakarta") == 0) {
                printf("Jawaban Benar");
                break;
            }
        }
        printf("Jawaban Salah \n");
    }

    return 0;
}
