#include<stdio.h>

void main(){
	int x=1, y=2, z=3;
	if(x--)						//x--�õ���ֵΪ1, ��ִ��y++��z++ 
		y++, z++;				//�����������, x=0, y=3, z=4 
	else
		y--;
		z--;					//����z��-1, ���z=3 
	printf("%d,%d,%d\n",x,y,z);
} 
