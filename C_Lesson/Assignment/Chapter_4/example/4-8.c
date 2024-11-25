#include<stdio.h>
#include<windows.h>

void main(){
	int year,leap;
	printf("输入年份: ");
	scanf("%d",&year);
	if (year%400 == 0){
		leap = 1;								//是闰年 
	}else{
		if (year%4 == 0 && year%100 != 0){
			leap = 1;							//是闰年 
		}else{
			leap = 0;							//不是闰年 
		}
	}
	if (leap == 1){
		printf("%d: 是闰年",year);
	}else{
		printf("%d: 不是闰年",year);
	} 
	system("pause");
}
