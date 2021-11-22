#include <stdio.h>
#include <string.h>

char a[20];

int main(){
	int i,j,n;
	printf("A : "); gets(a);
	n = strlen(a);
	for(i=0; i<n; i++){
		printf("%.*s \n", i, a);
	}
	for(i=n; i>0; i--){
		printf("%.*s \n", i, a);
	}
	return 0;
}
