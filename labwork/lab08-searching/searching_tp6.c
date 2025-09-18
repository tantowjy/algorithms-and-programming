#include <stdio.h>
#include <string.h>

char cr, string[100];
int i, n;

void main() {
    printf("Masukan string : ");
    gets(string);
    printf("Karakter yang dicari : ");
    scanf("%c", &cr);
    n = strlen(string);
    for (i = 0; i < n; i++) {
        if (cr == string[i]) {
            printf("Karakter %c ada diurutan : %d", cr, i + 1);
            break;
        } else if (i == n - 1) {
            printf("Data tidak ditemukan");
        }
    }
}
