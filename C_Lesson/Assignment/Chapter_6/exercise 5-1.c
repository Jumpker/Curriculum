#include<stdio.h>

int Fibonacci(int n){
	if(n == 1 || n == 2)
		return 1;
	else
		return Fibonacci(n-1) + Fibonacci(n-2);
}

void main(){
	int i=1, x; 
	printf("请输入一个自然数, 我会输出不小于该自然数的最小的斐波那契数: \n");
	scanf("%d",&x);
	for(i=1; Fibonacci(i)<x; i++);
	printf("%d\n",Fibonacci(i));
}

