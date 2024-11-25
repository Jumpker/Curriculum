#include<stdio.h>
#include<windows.h>
#include<math.h>

void main(){
	float a,b,c,x1,x2,disc;
	printf("输入a b c:");
	scanf("%f %f %f",&a,&b,&c);
	if (fabs(a) < 1e-6){											//a == 0; 很奇怪,开始不知道fabs()这个 
		printf("该方程不是二次方程");}							//函数是干嘛的,去查了发现是绝对值 
	else{ 
		disc = b*b - 4*a*c; 
		if(disc < 0){
			printf("该方程没有实根");}
		else{
			if (fabs(disc) < 1e-6){								//判别式等于0
			printf("该方程有两个相等的实根: %8.4f",-b/(2*a));} 
			else{
				x1 = (-b + sqrt(disc))/(2*a);
				x2 = (-b - sqrt(disc))/(2*a);
				printf("该方程有两个不等实根: %8.4f和%8.4f",x1,x2);} 
			}
		}
	system("pause");
}
