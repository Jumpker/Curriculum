#include<stdio.h>

void main(){
	float s=1.0;
	int k=1, n=2;
	while(k<=n){
		s = s + 1.0/(k*(k+1));
		k++;
	}
	printf("s = %f\n",s);
}
