#include<stdio.h>

void fun(int a, int b, int c){
	c = a*a + b*b;
}

void main(){
	int x = 22;
	fun(4,2,x);
	printf("%d",x);
}
