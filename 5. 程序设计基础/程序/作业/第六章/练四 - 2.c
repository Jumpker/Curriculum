#include<stdio.h>

int fun(int n){
	int g, s, b;
	g = n % 10;
	s = n / 10 % 10;
	b = n / 100;
	if(s == g+b)
		return 1;
	else
		return 0;
} 

void main(){
	int num;
	printf("��������: \n");
	scanf("%d", &num);
	if(fun(num))
		printf("�����: yes!\n");
	else
		printf("�����: no!\n");
}
