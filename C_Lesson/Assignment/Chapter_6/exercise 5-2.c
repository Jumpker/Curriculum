#include<stdio.h>

int F(n){
	if(n==0 || n==1)
		return 1;
	else if(n == 2)
		return 0;
	else
		return (F(n-1) - 3*F(n-2) + 2*F(n-3));
}

void main(){
	int i, count=0, max=1, min=0;
	for(i=0; i<=10; i++){
		if(F(i) == 0)
			count++;
		if(F(i) > max)
			max = F(i);
		if(F(i) < min)
			min = F(i);
	} 
	printf("F(0)到F(10)中的最大值为: %d\n",max);
	printf("F(0)到F(10)中的最小值为: %d\n",min);
	printf("F(0)到F(10)中共有%d个值等于0的数\n",count);
}
