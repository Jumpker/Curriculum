#include<stdio.h>
void main(){
	int i, x, y=1;
	scanf("%d",&x);
	for(i=2; i<=x/2; i++)
		if(x%i == 0){y=0;break;}
	printf("%d\n",y);
}
