#include<stdio.h>
#include<malloc.h>
//---------------�ݹ��㷨--------------------- 
void Hanoil(int n, char a, char b, char c){
	if(n == 1)
		printf("\t����%d����Ƭ��%c�ƶ���%c\n",n,a,c);
	else{
		Hanoil(n-1,a,c,b);
		printf("\t����%d����Ƭ��%c�ƶ���%c\n",n,a,c);
		Hanoil(n-1,b,a,c);
	}
} 
//---------------------------------------------
int main(){
	int n = 3;
	printf("�ݹ��㷨: %d����Ƭ�ƶ�����:\n",n);
	Hanoil(n,'X','Y','Z');
	return 1;
} 
