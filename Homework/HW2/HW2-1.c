#include <stdio.h>
#include <stdlib.h>

int main(){

  long int i, x, y=1, z=0;

  printf("\n=== Penjumlahan Faktorial ===\n");
  printf("Masukkan bilangan: ");
  scanf("%ld", &x);

  if(x<0){
    printf("Error\n");
  } else if(x == 0){
    printf("%ld! = 1 \n", x);
  } else {
    for (i = 1; i <= x; i++) {
      y = y*i;
      z += y;
      if(i < x){
        printf("%ld! + ", i);
      } else if(i = x) {
        printf("%ld! = ", i);
      }
    }
    printf("%ld \n\n", z);
  }

}
