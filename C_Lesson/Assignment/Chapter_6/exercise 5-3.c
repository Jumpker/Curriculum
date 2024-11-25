#include<stdio.h>

int change(int x, int r){
	int i=x, result;
	if(x<r)
		result = x;
	else{
		result = 1;
		while(i >= r){
			result = i%r + result*10;
			i /= r;
		}
	}
	return result;
}

void main(){
	int x, r;
	printf("请输入你要转换的十进制整数x: \n");
	scanf("%d",&x);
	printf("你想把它转换成几进制数? \n");
	scanf("%d",&r);
	printf("%d转换为%d进制数的结果为: %d",x,r,change(x,r));
}
