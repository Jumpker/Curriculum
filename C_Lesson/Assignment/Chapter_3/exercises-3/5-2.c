#include<stdio.h>

void main(){
	int a,b,c;
	float l,S;
	printf("这是一个三角形面积计算器, 请输入该三角形的三边长, 注意用','隔开:\n");
	scanf("%d,%d,%d",&a,&b,&c);
	if (((a+b)>c) && ((b+c)>a) && ((a+c)>b)){
		l = (a+b+c)/2;
		S = sqrt(l*(l-a)*(l-b)*(l-c));
		printf("该三角形的面积 S = %f",S); 
	}else
		printf("你输入的三边构不成一个三角形!!");
} 
