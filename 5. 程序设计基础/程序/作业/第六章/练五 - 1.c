#include<stdio.h>

int Fibonacci(int n){
	if(n == 1 || n == 2)
		return 1;
	else
		return Fibonacci(n-1) + Fibonacci(n-2);
}

void main(){
	int i=1, x; 
	printf("请输入你的自然数: \n");
	scanf("%d",&x);
	for(i=1; Fibonacci(i)<x; i++);
	printf("%d\n",Fibonacci(i));
}

