#include<stdio.h>
#include<windows.h>
#include<math.h>

void main(){
	char ch = 'A';				//�����ַ��ͱ���, ������ֵ'A'
	int a, c;					//�������ͱ��� 
	float x1, x2=2.5; 			//���嵥���ȸ����ͱ���
	a = ch;						//���ַ��ͱ���ch��ֵ'A'�������ͱ���a
	x1 = a;
	c = x2;						//x2��ֵ2.5�������ͱ���c
	printf("\n%4c, %4d, %6.2f, %4d\n", ch,a,x1,c); 
}
