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
	int i, count, max=1, min=0;
	for(i=0; i<=10; i++){
		if(F(i) == 0)
			count++;
		if(F(i) > max)
			max = F(i);
		if(F(i) < min)
			min = F(i);
	} 
	printf("F(0)��F(10)�е����ֵΪ%d\n",max);
	printf("F(0)��F(10)�е���СֵΪ%d\n",min);
	printf("F(0)��F(10)��ֵ����0����%d��\n",count);
}
