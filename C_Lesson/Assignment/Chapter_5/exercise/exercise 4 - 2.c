#include<stdio.h>

void main(){
	int x, t;
	printf("请输入一个整数: ");
	scanf("%d",&x);
	printf("其二进制数的反序为: ");
	while(x!=0){
		t = x%2;
		x = x/2;
		printf("%d",t);
	}
}
