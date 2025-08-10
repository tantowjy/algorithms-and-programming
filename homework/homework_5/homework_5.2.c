#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char answer[100], answer1[100], answer2[100], answer3[100];
int i, j, p, q, r, s, n, x=0;
int crn, temp;
int a[4];

int abc(int n1, char cr[100], int b ){
	for(i=0; i<n1; i++){
		int crn = 1;
		for(j=i+1; j<n1; j++){
			if(cr[i] != cr[j]){
				break;
			}
			crn++;
		}
		if(crn > x){
			x = crn;
		}
	}
	a[b] = x;
}

void main(){
	printf("===HW5.2===\n");
	printf("Input JAWABAN (BS): "); gets(answer);
	printf("k = "); scanf("%d", &p);
	n = strlen(answer);
	strcpy(answer1, answer);
	strcpy(answer2, answer);
	strcpy(answer3, answer);
	q = p;
	r = p;
	s = p;
	// p 
	for(i=0; i<n; i++){
		while(answer[i]!='B' && p>0){
			if(answer[i]=='S'){
				answer[i] = 'B';
			}
			p--;
		}
	}
	abc(n, answer, 0);
	// q
	for(i=n-1; i>=0; i--){
		while(answer1[i]!='B' && q>0){
			if(answer1[i]=='S'){
				answer1[i] = 'B';
			}
			q--;
		}
	}
	abc(n, answer1, 1);
	// r
	for(i=0; i<n; i++){
		while(answer2[i]!='S' && r>0){
			if(answer2[i]=='B'){
				answer2[i] = 'S';
			}
			r--;
		}
	}
	abc(n, answer2, 2);
	// s
	for(i=n-1; i>=0; i--){
		while(answer3[i]!='S' && s>0){
			if(answer3[i]=='B'){
				answer3[i] = 'S';
			}
			s--;
		}
	}
	abc(n, answer3, 3);
	//
	for (i=3;i>=1;i--){
		for (j=1;j<=i;j++){
			if (a[j-1]>a[j]){
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
    }
    printf("Output: %d", a[3]);
}
