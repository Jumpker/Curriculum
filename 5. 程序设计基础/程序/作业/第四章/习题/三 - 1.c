#include<stdio.h>

void main(){
	int a=10, b=20, c=30, d;
	d = ++a <= 10 || b-- >=20 || c++;
	printf("%d,%d,%d,%d\n",a,b,c,d);
}
