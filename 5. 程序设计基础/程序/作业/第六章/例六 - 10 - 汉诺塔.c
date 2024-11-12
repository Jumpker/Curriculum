#include<stdio.h>
#include<windows.h>

void hanoi(int n, int a, int b, int c){
	if(n == 1)
		printf("%d->%d\n",a,c);					//n==1时, 直接将金片从a移到c 
	else{
		hanoi(n-1, a, c, b);					//n-1个金片从a移动到c
		printf("%d->%d\n",a,c);					//将第n个金片从a移动到c
		hanoi(n-1, b, a, c);					//将n-1个金片从b经过a移动到c	 
	}
}

void main(){
	int n;
	printf("input n:");
	scanf("%d", &n);							//输入金片个数 
	hanoi(n, 1, 2, 3);							//n个金片从第一根轴经过第二根轴移动到第三根轴 
	system("pause");
}
