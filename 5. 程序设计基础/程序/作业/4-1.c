#include<stdio.h>
void main(){
	int a, b, c, t;
	printf("输入三个整数: ");
	scanf("%d,%d,%d",&a,&b,&c);
	t = (a>b)?((a>c)?a:c):((b>c)?b:c);
	printf("3数中最大的为:%d\n",t);
}
