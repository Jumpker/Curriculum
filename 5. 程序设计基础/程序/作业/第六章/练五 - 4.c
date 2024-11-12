#include<stdio.h>
int countp=0;

int su(int x){
	int i, flag;
	if(x==1)
		flag = 0;
	else if(x==2 || x==3)
		flag = 1;
	else{
		for(i=2; i<=(x/2); i++)
			if(x%i == 0){
				flag = 0;break;}
			else
				flag = 1; 
	}
	return flag;
}

void print(int i){
	printf("%d\t",i);
	if(++countp%5 == 0)
		printf("\n");
}

void main(){
	int i, count=0, g, s, b;
	for(i=2; i<1000; i++){
		if(i<10 && su(i))						//10以内的素数, 直接输出 
			print(i);
		else if(i>=10 && i<100){				//10-100(两位数)
			g = i%10;
			s = i/10;
			if(su(g) && su(s) && su(g+s))
				print(i);
		}
		else if(i>=100 && i<1000){				//100-1000(三位数)
			g = i%10;
			s = i/10%10;
			b = i/100;
			if(su(g) && su(s) && su(b) && su(g+s+b))
				print(i);
		}
	}
}
