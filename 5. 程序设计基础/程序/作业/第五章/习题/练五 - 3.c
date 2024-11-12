#include<stdio.h>
#include<math.h>

float di(int n){
	if(n == 1)
		return 1;
	else if(n == 2)
		return sqrt(2);
	else
		return sqrt(2+di(n-1));
	
}
	
void main(){
	int n, i;
	float pi=1;
	printf("请输入精度(算到第几项?): ");
	scanf("%d",&n);
	for(i=1; i<=n; i++)
		pi *= (2/di(i));
	printf("%f",pi);
}
