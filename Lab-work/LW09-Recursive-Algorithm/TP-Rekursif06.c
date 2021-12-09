#include <stdio.h> 

int nFactorial(int n); 
int x, hasil; 

int main(){ 
	printf("=== Input ===\n"); 
	printf("Masukkan angka : "); scanf("%d", &x); 
	printf("=== Output ===\n"); 
	hasil = nFactorial(x); 
	printf("Hasil %d! adalah %d ", x, hasil); 
	return 0; 
} 

int nFactorial(int n){ 
	if(n == 1 || n == 0){ 
		return 1; 
	} else if(n>1){ 
		return n*nFactorial(n-1); 
	} 
}
