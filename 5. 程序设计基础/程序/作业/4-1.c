#include<stdio.h>
void main(){
	int a, b, c, t;
	printf("������������: ");
	scanf("%d,%d,%d",&a,&b,&c);
	t = (a>b)?((a>c)?a:c):((b>c)?b:c);
	printf("3��������Ϊ:%d\n",t);
}
