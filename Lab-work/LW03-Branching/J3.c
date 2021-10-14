#include <stdio.h>
#include <stdlib.h>

int p1, p2, l1, l2, t1, t2, vol1, vol2;

int main(){
  printf("Masukkan panjang akuarium 1 : ");
  scanf("%d", &p1);
  printf("Masukkan lebar akuarium 1 : ");
  scanf("%d", &l1);
  printf("Masukkan tinggi akuarium 1 : ");
  scanf("%d", &t1);
  printf("Masukkan panjang akuarium 2 : ");
  scanf("%d", &p2);
  printf("Masukkan lebar akuarium 2 : ");
  scanf("%d", &l2);
  printf("Masukkan tinggi akuarium 2 : ");
  scanf("%d", &t2);

  vol1 = p1*l1*t1;
  vol2 = p2*l2*t2;

  printf("Rayhan akan membeli ");
  if  (vol1>vol2){
        printf("akuarium 1\n");
        printf("Volume akuarium 1: %d\n", vol1);
        printf("Volume akuarium 2: %d\n", vol2);
  } else if (vol1<vol2){
        printf("akuarium 2\n");
        printf("Volume akuarium 1: %d\n", vol1);
        printf("Volume akuarium 2: %d\n", vol2);
  } else {
        printf("akuarium 1 atau akuarium 2\n");
        printf("Volume akuarium 1: %d\n", vol1);
        printf("Volume akuarium 2: %d\n", vol2);
  }
  return 0;
}
