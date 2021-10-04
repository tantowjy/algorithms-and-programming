#include <stdio.h>
#include <stdlib.h>

int main(){

  int i,j,k;

  printf("\n=== Bentuk Wajik ===\n");
  printf("\nEnter the limit : \t");
  scanf("%d", &k);

  for (i=1; i<=k; i++){
    for(j=1; j<=2*k-i; j++){
      printf(" ");
    }
    for(j=1; j<=i; j++){
      printf("* ");
    }
    printf("\n");
  }
  for(i=k-1; i>= 1; i--){
    for(j=1; j<=2*k-i; j++){
      printf(" ");
    }
    for(j=1; j<= i; j++){
      printf("* ");
    }
    printf("\n");
  }

}
