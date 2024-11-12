#include<stdio.h>

void main(){
	int a,b;
	printf("输入一个三位数: ");
	scanf("%d",&a);
	b = (a%10)*100 + (a/10%10)*10 + (a/100);
	printf("反序为: %d\n",b);
} 
