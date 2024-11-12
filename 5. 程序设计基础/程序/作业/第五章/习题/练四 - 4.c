#include<stdio.h>

void main(){
	int i, j;
	for(i=1; i<=5; i++){
		for(j=1; j<=5-i; j++)				//打印空格 
			printf(" ");
		for(j=1; j<=2*i-1; j++)				//打印数字1~j 
			printf("%d",j);
		printf("\n");				//换行 
	}
}
