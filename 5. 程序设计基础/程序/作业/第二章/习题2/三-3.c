#include<stdio.h>

void main(){
	int a=1, b=2, c=3;
	printf("%d,%d,%d,%d\n", a=b=c, a=b==c, a==(b=c), a==(b==c));
} 
	//第一个是先把c的值赋给b, 再把b的值赋给a, 此时abc都为3, 打印3
	//第二个先运算b==c, 此时b和c都为3, 所以b==c的结果为1, 则此时把1赋给a...
	//???怎么回事, 怎么会是3呢, 后面也因此不对了啊 
