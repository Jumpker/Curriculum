#include<stdio.h>

void main(){
	int a;
	printf("������һ��3λ���ڵ�����a\n");
	scanf("%d",&a);
	if(a/1000 == 0 && a/100 >= 1)
		printf("3\n");
	else if(a/100 == 0 && a/10 >= 1)
		printf("2\n");
	else
		printf("1\n");
}
