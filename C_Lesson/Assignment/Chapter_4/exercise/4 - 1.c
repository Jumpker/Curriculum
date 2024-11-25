#include<stdio.h>

void main(){
	int c;
	c = getchar();
	if(c-'0' >= 0 && c-'9' <= 0)
		c -= '0';
	printf("%d",c);
}
