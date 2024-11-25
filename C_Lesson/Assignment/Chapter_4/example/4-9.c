#include<stdio.h>
#include<windows.h>

void main(){
	int a,b;
	char c;
	scanf("%d %c %d",&a,&c,&b);
	switch(c){
		case'+':printf("a + b = %d",a+b);break;
		case'-':printf("a - b = %d",a-b);break;
		case'*':printf("a * b = %d",a*b);break;
		case'/':{
			if(b != 0)
				printf("a / b = %d",a/b);
			else
				printf("b = 0");
		}break;
		case'%':{
			if(b != 0)
				printf("a mod b = %d",a%b);
			else
				printf("b = 0");
		}
		default: printf("Data out of range");
	}
	system("pause");
} 
