#include <stdio.h>

struct PesananBolu {
	char name[50], address[50];
	int price;
} bolu[100];

void main(){
	int n,i;
	printf("Jumlah yang membeli : ");
	scanf("%d", &n);
	fflush(stdin);
	for(i=0;i<=n-1; i++){
		printf("%d. Nama Pembeli : ", i+1); gets(bolu[i].name);
		printf("Alamat : "); gets(bolu[i].address);
		printf("Harga : "); scanf("%d", &bolu[i].price); 
		fflush(stdin);
	}
	printf("\n\nDaftar Pesanan Bolu:\n");
	for(i=0;i<=n-1; i++){
		printf("%d. Nama Pembeli : %s \n", i+1, bolu[i].name);
		printf("Alamat : %s \n", bolu[i].address);
		printf("Harga : Rp%d ", bolu[i].price);
		printf("\n");
	}
}
