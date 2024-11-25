#include<stdio.h>
#include<windows.h>
#include<math.h>

void main(){
	char ch = 'A';				//定义字符型变量, 并赋初值'A'
	int a, c;					//定义整型变量 
	float x1, x2=2.5; 			//定义单精度浮点型变量
	a = ch;						//将字符型变量ch的值'A'赋给整型变量a
	x1 = a;
	c = x2;						//x2的值2.5赋给整型变量c
	printf("\n%4c, %4d, %6.2f, %4d\n", ch,a,x1,c); 
}
