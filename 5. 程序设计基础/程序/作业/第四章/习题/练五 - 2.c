#include<stdio.h>
#include<math.h> 

void main(){
	double x,y;
	printf("请输入x: ");
	scanf("%lf",&x);
	switch((int)sqrt(x)){
	case 10: printf("y无定义");break;
	case 9: printf("y = %2.0lf",x+2);break;
	case 8: printf("y = %2.0lf",2*x+3);break;
	case 7: printf("y = %2.0lf",2*x+4);break;
	case 6: printf("y = %2.0lf",4*x+5);break;
	default: printf("y无定义"); 
	}
}
