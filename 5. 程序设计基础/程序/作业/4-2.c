#include<stdio.h>

void main()
{
	float F,C;
	printf("请输入华氏温度: ");
	scanf("%f",&F);
	C =  5*(F- 32)/9;
	printf("摄氏温度为%f\n",C);
 } 
