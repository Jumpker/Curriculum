#include<stdio.h>

void main(){
	int a,b,c;
	float l,S;
	printf("����һ�����������������, ������������ε����߳�, ע����','����:\n");
	scanf("%d,%d,%d",&a,&b,&c);
	if (((a+b)>c) && ((b+c)>a) && ((a+c)>b)){
		l = (a+b+c)/2;
		S = sqrt(l*(l-a)*(l-b)*(l-c));
		printf("�������ε���� S = %f",S); 
	}else
		printf("����������߹�����һ��������!!");
} 
