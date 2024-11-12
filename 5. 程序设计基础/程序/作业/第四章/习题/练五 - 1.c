#include<stdio.h>
#include<math.h>

void main(){
	double a,x,y;
	printf("请输入两个两位小数a、x, 中间用空格隔开\n");
	scanf("%lf %lf",&a,&x); 
	if(fabs(x) == a){
		y = 0;
		printf("得到的结果为: %8.2lf",y);}
	else{
		if(fabs(a) == x)
			printf("数学错误! ln(x)中x不能小于等于0!"); 
		else if(x == a)
			printf("数学错误! 分母不能为0!");
		else{
		y = (log(fabs((a+x)/(a-x)))) / (2*a);
		printf("得到的结果为: %8.2lf",y);
		}
	}
}
