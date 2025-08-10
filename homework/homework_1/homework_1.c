#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char day[8];
  int n;

  printf("Hari ini: ");
  scanf("%s", day);

  printf("Jumlah hari ke depan: ");
  scanf("%d", &n);

  if (strcmp(day, "Minggu") == 0){
    if (n % 7 == 0) {
      printf("%d hari setelah hari %s adalah Minggu \n", n, day);
    } else if (n % 7 == 1){
      printf("%d hari setelah hari %s adalah Senin \n", n, day);
    } else if (n % 7 == 2){
      printf("%d hari setelah hari %s adalah Selasa \n", n, day);
    } else if (n % 7 == 3){
      printf("%d hari setelah hari %s adalah Rabu \n", n, day);
    } else if (n % 7 == 4){
      printf("%d hari setelah hari %s adalah Kamis \n", n, day);
    } else if (n % 7 == 5){
      printf("%d hari setelah hari %s adalah Jumat \n", n, day);
    } else if (n % 7 == 6){
      printf("%d hari setelah hari %s adalah Sabtu \n", n, day);
    }
  } else if (strcmp(day, "Senin") == 0){
    if (n % 7 == 0) {
      printf("%d hari setelah hari %s adalah Senin \n", n, day);
    } else if (n % 7 == 1){
      printf("%d hari setelah hari %s adalah Selasa \n", n, day);
    } else if (n % 7 == 2){
      printf("%d hari setelah hari %s adalah Rabu \n", n, day);
    } else if (n % 7 == 3){
      printf("%d hari setelah hari %s adalah Kamis \n", n, day);
    } else if (n % 7 == 4){
      printf("%d hari setelah hari %s adalah Jumat \n", n, day);
    } else if (n % 7 == 5){
      printf("%d hari setelah hari %s adalah Sabtu \n", n, day);
    } else if (n % 7 == 6){
      printf("%d hari setelah hari %s adalah Minggu \n", n, day);
    }
  } else if (strcmp(day, "Selasa") == 0){
    if (n % 7 == 0) {
      printf("%d hari setelah hari %s adalah Selasa \n", n, day);
    } else if (n % 7 == 1){
      printf("%d hari setelah hari %s adalah Rabu \n", n, day);
    } else if (n % 7 == 2){
      printf("%d hari setelah hari %s adalah Kamis \n", n, day);
    } else if (n % 7 == 3){
      printf("%d hari setelah hari %s adalah Jumat \n", n, day);
    } else if (n % 7 == 4){
      printf("%d hari setelah hari %s adalah Sabtu \n", n, day);
    } else if (n % 7 == 5){
      printf("%d hari setelah hari %s adalah Minggu \n", n, day);
    } else if (n % 7 == 6){
      printf("%d hari setelah hari %s adalah Senin \n", n, day);
    }
  } else if (strcmp(day, "Rabu") == 0){
    if (n % 7 == 0) {
      printf("%d hari setelah hari %s adalah Rabu \n", n, day);
    } else if (n % 7 == 1){
      printf("%d hari setelah hari %s adalah Kamis \n", n, day);
    } else if (n % 7 == 2){
      printf("%d hari setelah hari %s adalah Jumat \n", n, day);
    } else if (n % 7 == 3){
      printf("%d hari setelah hari %s adalah Sabtu \n", n, day);
    } else if (n % 7 == 4){
      printf("%d hari setelah hari %s adalah Minggu \n", n, day);
    } else if (n % 7 == 5){
      printf("%d hari setelah hari %s adalah Senin \n", n, day);
    } else if (n % 7 == 6){
      printf("%d hari setelah hari %s adalah Selasa \n", n, day);
    }
  } else if (strcmp(day, "Kamis") == 0){
    if (n % 7 == 0) {
      printf("%d hari setelah hari %s adalah Kamis \n", n, day);
    } else if (n % 7 == 1){
      printf("%d hari setelah hari %s adalah Jumat \n", n, day);
    } else if (n % 7 == 2){
      printf("%d hari setelah hari %s adalah Sabtu \n", n, day);
    } else if (n % 7 == 3){
      printf("%d hari setelah hari %s adalah Minggu \n", n, day);
    } else if (n % 7 == 4){
      printf("%d hari setelah hari %s adalah Senin \n", n, day);
    } else if (n % 7 == 5){
      printf("%d hari setelah hari %s adalah Selasa \n", n, day);
    } else if (n % 7 == 6){
      printf("%d hari setelah hari %s adalah Rabu \n", n, day);
    }
  } else if (strcmp(day, "Jumat") == 0){
    if (n % 7 == 0) {
      printf("%d hari setelah hari %s adalah Jumat \n", n, day);
    } else if (n % 7 == 1){
      printf("%d hari setelah hari %s adalah Sabtu \n", n, day);
    } else if (n % 7 == 2){
      printf("%d hari setelah hari %s adalah Minggu \n", n, day);
    } else if (n % 7 == 3){
      printf("%d hari setelah hari %s adalah Senin \n", n, day);
    } else if (n % 7 == 4){
      printf("%d hari setelah hari %s adalah Selasa \n", n, day);
    } else if (n % 7 == 5){
      printf("%d hari setelah hari %s adalah Rabu \n", n, day);
    } else if (n % 7 == 6){
      printf("%d hari setelah hari %s adalah Kamis \n", n, day);
    }
  } else if (strcmp(day, "Sabtu") == 0){
    if (n % 7 == 0) {
      printf("%d hari setelah hari %s adalah Sabtu \n", n, day);
    } else if (n % 7 == 1){
      printf("%d hari setelah hari %s adalah Minggu \n", n, day);
    } else if (n % 7 == 2){
      printf("%d hari setelah hari %s adalah Senin \n", n, day);
    } else if (n % 7 == 3){
      printf("%d hari setelah hari %s adalah Selasa \n", n, day);
    } else if (n % 7 == 4){
      printf("%d hari setelah hari %s adalah Rabu \n", n, day);
    } else if (n % 7 == 5){
      printf("%d hari setelah hari %s adalah Kamis \n", n, day);
    } else if (n % 7 == 6){
      printf("%d hari setelah hari %s adalah Jumat \n", n, day);
    }
  } else {
    printf("\n\n   =============================");
    printf("\n     !!PENULISAN HARI SALAH!!");
    printf("\n   =============================");
    printf("\n   Penulisan hari yang benar:");
    printf("\n   ==> Minggu \n   ==> Senin \n   ==> Selasa \n   ==> Rabu \n   ==> Kamis \n   ==> Jumat \n   ==> Sabtu");
    printf("\n   =============================\n\n");
  }
}
