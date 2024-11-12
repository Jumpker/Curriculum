#include<stdio.h>
void main(){
	int x, y;
	for(x=y=1; x<=100; x++){
		if(y>=10)break;
		if(y%3 == 1){
			y = y+3;continue;}		//y依次被赋值为1,4,7,10 
	}								//此时for一共循环了四次 
	printf("%d\n",x);
} 
