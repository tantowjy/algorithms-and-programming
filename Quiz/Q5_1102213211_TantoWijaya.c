#include <stdio.h>

int main(){
  int n1,n2,i,fpb,kpk;

  printf("Masukkan angka pertama : ");
  scanf("%d", &n1);
  printf("Masukkan angka kedua : ");
  scanf("%d", &n2);

  for(i=1; i<=n1 && i <= n2; i++){
    if(n1%i==0 && n2%i==0){
      fpb = i;
    }
  }

  kpk = (n1*n2)/fpb;

  printf("%d \n", fpb);
  printf("%d", kpk);

  return 0;

}
