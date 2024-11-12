#include<stdio.h>
float fei_bo_na_qi(int n){

	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	else
		return fei_bo_na_qi(n-1) + fei_bo_na_qi(n-2);
}

void main(){
	int n;
	float x, sum;
	printf("你要输出前多少项和? \n");
	scanf("%d",&n);
	int i;
	for(i=2; i<=n+1; i++){
		x = fei_bo_na_qi(i-1)/fei_bo_na_qi(i);
		printf("第%d个项为: %f\n",i-1, x);
		sum += x;
	}
	printf("其前%d项和为%f。",n,sum);
} 
