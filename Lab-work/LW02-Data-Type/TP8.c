#include <stdio.h> 

int main(){ 
	float R1,R2,R3; 
	printf("===INPUT (Poin A)===\n"); 
	printf("Masukan R1 : "); scanf("%f", &R1); 
	printf("Masukan R2 : "); scanf("%f", &R2); 
	printf("Masukan R3 : "); scanf("%f", &R3); 
	printf("===OUTPUT===\n"); 
	printf("Hambatan total pada rangkaian = %.2f Ohm", R1+R2+R3); 
}
