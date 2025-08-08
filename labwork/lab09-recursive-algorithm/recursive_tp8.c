#include <stdio.h> 

int bilGenap(int m, int n); 
int x, y=0; 

int main(){ 
	printf("=== INPUT === \n"); 
	printf("Masukkan banyak suku : "); scanf("%d", &x); 
	printf("\n=== OUTPUT === \n"); 
	printf("Hasil : "); 
	bilGenap(x,y); 
	return 0; 
} 

int bilGenap(int m, int n){ 
	if(m > 0){ 
		printf("%d ", n+2); 
		return bilGenap(m-1, n+2); 
	} 
}
