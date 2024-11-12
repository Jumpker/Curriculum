#include<stdio.h>

void main(){
	int num1,num2,num3;
	float average;
	printf("Please input three numbers (注意用','隔开): ");
	scanf("%d,%d,%d",&num1,&num2,&num3);
	average = (num1 + num2 + num3)/3.0;				//注意这里的3.0, 必须是有小数精度的
	printf("average = %7.2f\n",average); 
}
