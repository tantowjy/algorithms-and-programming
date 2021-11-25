#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nama[100][100], bolu[100][100], harga[100][100], temp1[100], temp2[100], temp3[100];
int i,j,n,max;

void main(){
	  printf("===INPUT===\n");
	  printf("Jumlah pembeli : "); scanf("%d", &n);
	  getchar();
	  for(i=0; i<n; i++){
	    printf("%d. Nama : ", i+1); gets(nama[i]);
	    printf("Bolu : "); gets(bolu[i]);
	    printf("Harga : "); gets(harga[i]);
	  }
	  for(i=0; i<n; i++){
	    max=i;
	    for(j=i; j<n; j++){
	      if(strcmp(nama[max], nama[j])>0){max=j;}
	    }
	    strcpy(temp1, nama[max]);
	    strcpy(nama[max], nama[i]);
	    strcpy(nama[i], temp1);
	    strcpy(temp2, bolu[max]);
	    strcpy(bolu[max], bolu[i]);
	    strcpy(bolu[i], temp2);
	    strcpy(temp3, harga[max]);
	    strcpy(harga[max], harga[i]);
	    strcpy(harga[i], temp3);
	  }
	  printf("===OUTPUT===\nHasil Pengurutan : \n");
	  for(i=0; i<n; i++){
	    printf("%d. Nama : %s \n", i+1, nama[i]);
	    printf("Bolu : %s \n", bolu[i]);
	    printf("Harga : %s \n", harga[i]);
	    
	  }
}
