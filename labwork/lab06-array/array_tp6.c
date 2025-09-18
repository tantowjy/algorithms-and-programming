#include <stdio.h>
#include <string.h>

char string1[100], string2[100];

void main() {
    printf("===INPUT===\n");
    printf("Masukan String 1 : ");
    gets(string1);
    printf("Masukan String 2 : ");
    gets(string2);
    printf("===OUTPUT===\n");
    printf("Panjang String 1 : %d \n", strlen(string1));
    printf("Panjang String 2 : %d \n", strlen(string2));
    if (strlen(string1) > strlen(string2)) {
        printf("String 1 lebih panjang daripada string 2");
    } else if (strlen(string2) > strlen(string1)) {
        printf("String 2 lebih panjang daripada string 1");
    } else {
        printf("String 1 dan string 2 sama panjang");
    }
}
