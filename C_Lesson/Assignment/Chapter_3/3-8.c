#include<stdio.h>

void main(){
	int num1,num2,num3;
	float average;
	printf("Please input three numbers (ע����','����): ");
	scanf("%d,%d,%d",&num1,&num2,&num3);
	average = (num1 + num2 + num3)/3.0;				//ע�������3.0, ��������С�����ȵ�
	printf("average = %7.2f\n",average); 
}
