#include <stdio.h>

int prima(int n){
  int i,prima=0;
  for (i=2; i<=n/2; i++){
    if (n%i == 0){
      prima = 1;
      break;
    }
  }
  if (!prima){
    printf("%d ", n);
  }
}

int deretprima(int x){
  int i;
  for(i=2; i<=x; i++){
    prima(i);
  }
}

int main(){
  int x;
  printf("Masukkan batas : ");
  scanf("%d", &x);
  deretprima(x);
  printf("\n");
}
