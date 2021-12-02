#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pesanan{
	char nama[50], bolu[50];
} p[50];

char xnama[50], xbolu[50];
int i,n,x, y=0;


void main(){
	printf("===INPUT===\n");
	printf("Jumlah pesanan : "); scanf("%d", &n);
	getchar();
	for(i=0; i<n; i++){
		printf("%d. Nama : ", i+1); gets(p[i].nama);
		printf(" Bolu : "); gets(p[i].bolu);
	}
	
	printf("\n Pilih pencarian: \n");
	printf("1. Nama pemesan \n");
	printf("2. Bentuk bolu \n");
	printf("Pilih : "); scanf("%d", &x);
	getchar();
	printf("\n");
	if(x == 1){
		printf("Masukkan nama : "); gets(xnama);
		for(i=0; i<n; i++){
			if(strcmp(xnama, p[i].nama) == 0){
				y++;
				printf("%d Nama : %s \n", y, p[i].nama);
				printf(" Bentuk Bolu : %s \n", p[i].bolu);
			}
		}
	} else if (x == 2){
		printf("Masukkan bentuk bolu : "); gets(xbolu);
		for(i=0; i<n; i++){
			if(strcmp(xbolu, p[i].bolu) == 0){
				y++;
				printf("%d Nama : %s \n", y, p[i].nama);
				printf(" Bentuk Bolu : %s \n", p[i].bolu);
			}
		}
	} else {
		printf("Angka yang dipilih tidak ada");
	}
}
