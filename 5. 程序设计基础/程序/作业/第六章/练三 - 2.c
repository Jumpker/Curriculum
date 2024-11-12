#include<stdio.h>
#define SUB(x,y) (x)*y

void main(){
	int a=3, b=4, c;
	c = SUB(a++,b++);
	printf("%d,%d,%d\n",a,b,c);
}
