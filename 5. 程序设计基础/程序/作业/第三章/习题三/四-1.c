#include<stdio.h>

void main(){
	int a,b;
	printf("����һ����λ��: ");
	scanf("%d",&a);
	b = (a%10)*100 + (a/10%10)*10 + (a/100);
	printf("����Ϊ: %d\n",b);
} 
