#include<stdio.h>
long fun(int n){
	int i;
	long s = 1;
	for(i=1; i<=n; i++)
		s = i*(i-1);
	return s;
} 

void main(){
	long s = 0;
	int k, n;
	scanf("%d",&n);
	for(k=1; k<=n; k++)
		s = s + fun(k);
	printf("%ld\n",s);
}
