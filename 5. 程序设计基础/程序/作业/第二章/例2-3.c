#include<stdio.h>
#include<math.h>
#define PI 3.14159				//�������ַ�����PI

void main(){
	int a=3, b=3, c=4, d=2;
	float x=2, y1,y2;
	a = a*b + c/2;
	y1 = 46 + 2*PI*d;
	y2 = a*sin(x) + b*cos(x);
	
	//�����������û��, �����������
	printf("a = %d\n y1 = %lf\n y2 = %lf\n",a,y1,y2);
} 
