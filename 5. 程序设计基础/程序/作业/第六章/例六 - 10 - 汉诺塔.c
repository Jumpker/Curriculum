#include<stdio.h>
#include<windows.h>

void hanoi(int n, int a, int b, int c){
	if(n == 1)
		printf("%d->%d\n",a,c);					//n==1ʱ, ֱ�ӽ���Ƭ��a�Ƶ�c 
	else{
		hanoi(n-1, a, c, b);					//n-1����Ƭ��a�ƶ���c
		printf("%d->%d\n",a,c);					//����n����Ƭ��a�ƶ���c
		hanoi(n-1, b, a, c);					//��n-1����Ƭ��b����a�ƶ���c	 
	}
}

void main(){
	int n;
	printf("input n:");
	scanf("%d", &n);							//�����Ƭ���� 
	hanoi(n, 1, 2, 3);							//n����Ƭ�ӵ�һ���ᾭ���ڶ������ƶ����������� 
	system("pause");
}
