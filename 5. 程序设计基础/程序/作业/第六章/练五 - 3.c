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
	printf("��������Ҫת��������: \n");
	scanf("%d",&x);
	printf("��Ҫת��Ϊʲô������? \n");
	scanf("%d",&r);
	printf("%dת��Ϊ%d��������Ϊ: %d",x,r,change(x,r));
}
