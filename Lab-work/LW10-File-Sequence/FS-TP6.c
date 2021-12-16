#include <stdio.h> 

int main(){ 
	FILE *f_teks; 
	char string[255]; 
	
	printf("===INPUT===\n"); 
	f_teks = fopen("kalimat.txt", "w"); 
	printf("Masukkan kalimat : "); 
	gets(string); 
	fprintf(f_teks, "%s\n", string); 
	fclose(f_teks); 
	
	printf("\n===OUTPUT===\n"); 
	f_teks = fopen("kalimat.txt", "r"); 
	while(fgets(string, sizeof(string), f_teks)) 
	printf("%s", string); 
	fclose(f_teks); 
	
	return 0; 
}
