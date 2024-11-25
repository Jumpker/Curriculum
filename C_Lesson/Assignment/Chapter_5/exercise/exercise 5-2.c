#include<stdio.h>
#include<math.h>

int jie_cheng(int n){
	int i, result=1;
	for(i=1; i<=n; i++){
		result *= i;
	}
	return result;
}

float mi(float x, int n){
	int i, result=1;
	if (n > 0){
		for(i=1; i<=n; i++)
			result *= x;
		return result;
	} 
	else if(n == 0)
		return 1;
	else{
		n = -n;
		return 1/mi(x,n);
	}
}

float xiang(float x, int n){
	if(n == 1)
		return 1;
	else
		return mi(-1,(n-1)) * (mi(x,(2*n-2)) / jie_cheng(2*n-2));
}

void main(){
	double x, j=5;
	float cos1;
	printf("��������x��!\n");
	scanf("%lf",&x);
	int i;
	for (i=1; i<=j; i++){
		cos1 += xiang(x,i);
		printf("��%d����Ϊ%f\n",i, xiang(x,i));
	}
	printf("�õ��Ľ����: %.5f\n",cos1);
	printf("��ʵ�Ľ����: %.5lf\n\n",cos(x));
}
