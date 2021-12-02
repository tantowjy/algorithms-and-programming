#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
struct mhs { 
	char nama[50], nim[20]; 
} a[50]; 

char x[20]; 
int i,n; 

void main(){ 
	printf("===INPUT===\n"); 
	printf("Banyak mahasiswa : "); scanf("%d", &n); 
	getchar(); 
	for(i=0; i<n; i++){ 
	printf("%d. Nama : ", i+1); gets(a[i].nama); 
	printf(" NIM : "); gets(a[i].nim); } 
	printf("NIM Mahasiswa yang dicari : "); gets(x); 
	printf("===OUTPUT (bagian A)===\n"); 
	for(i=0; i<n; i++){ 
	if(strcmp(x, a[i].nim) == 0){ 
	printf("%s dengan NIM %s ada di urutan %d", a[i].nama, a[i].nim, i+1); 
	break; } 
	else if(i == n-1){ 
	printf("Mahasiswa dengan NIM %s tidak ditemukan", x); } } }
