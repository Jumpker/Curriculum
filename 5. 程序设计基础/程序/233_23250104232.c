#include<stdio.h>
void main()
{
	int a=1, b=2, c=3;
	printf("%d,%d,%d,%d\n", a=b=c, a=b==c, a==(b=c), a==(b==c));
} 
