#include<stdio.h>

void main(){
	int a;
	printf("请输入一个3位以内的整数a\n");
	scanf("%d",&a);
	if(a/1000 == 0 && a/100 >= 1)
		printf("3\n");
	else if(a/100 == 0 && a/10 >= 1)
		printf("2\n");
	else
		printf("1\n");
}
