#include<stdio.h>

void main(){
	int x, t;
	printf("������һ������: ");
	scanf("%d",&x);
	printf("����������ķ���Ϊ: ");
	while(x!=0){
		t = x%2;
		x = x/2;
		printf("%d",t);
	}
}
