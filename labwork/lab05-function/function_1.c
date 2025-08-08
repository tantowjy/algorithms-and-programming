//Program login session
#include <stdio.h>
#include <string.h> //(A). Tentukan Library

int main()
{
	char user[50], pass[50]; //(B). Tentukan tipe data
	printf("\t===LOGIN STATE===");
	printf("\nMasukkan Username \t: ");
	gets(user);
	printf("\nMasukkan Password \t: ");
	gets(pass);

	if(strcmp (user, "iamadmin")==0 && strcmp(pass, "@dasKOM1")==0) //(C). Lengkapi sintaks
	{
		printf("\nLogin Berhasil"); printf("\nSilahkan Lanjutkan...\n");
	}
	else
	{
		printf("\nUsername atau password salah!\n");
		printf("Silahkan Ulang");
	}
	return 0;
}
