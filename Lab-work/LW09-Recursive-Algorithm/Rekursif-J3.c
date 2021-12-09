// username : daskom
// password : daskom123

#include <stdio.h>

void login(int n);

int main(){
	printf("\n LOGIN \n");
	login(3);
	return 0;
}

void login(int n){
	char un[20], pw[20];
	if(n > 0){
		printf("username : "); gets(un);
		printf("password : "); gets(pw);
		if(strcmp(un,"daskom") == 0 && strcmp(pw, "daskom123") == 0){
			printf("LOGIN SUCCESS");
		} else {
			return login(n-1);
		}
	} else {
		printf("LOGIN FAILED");
	}
}
