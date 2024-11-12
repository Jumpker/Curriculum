#include<stdio.h>

int change(x,r){
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
	printf("请输入你要转换的整数: \n");
	scanf("%d",&x);
	printf("你要转换为什么进制数? \n");
	scanf("%d",&r);
	printf("%d转换为%d进制数后为: %d",x,r,change(x,r));
}
