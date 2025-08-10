#include <stdio.h>

void fibonanci(int a, int b, int n){
  static int x;
  if(n-2>0){
      x = a + b;
      a = b;
      b = x;
      printf("%d ", x);
      fibonanci(a,b,n-1);
  }
}

int main(){
  int a,b,n;

  printf("Bilangan pertama : "); scanf("%d", &a);
  printf("Bilangan kedua : "); scanf("%d", &b);
  printf("jumlah n barisan : "); scanf("%d", &n);

  printf("%d %d ", a,b);
  fibonanci(a,b,n);
  printf("\n");
}
