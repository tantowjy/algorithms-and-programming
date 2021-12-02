#include<stdio.h>
#include<string.h>

int main()
{
	char kalimat[50], cari;
	int i,n,hitung=0;
	printf(" Masukkan Kalimat : "); gets(kalimat);
	printf(" Huruf yang akan dihitung : ");
	scanf("%c", &cari);
	n=strlen(kalimat);
	for (i=0; i<n; i++){
		if (cari==kalimat[i]){
			hitung=hitung+1;
		}
	}
	printf(" Huruf %c ada %d", cari, hitung);
}

