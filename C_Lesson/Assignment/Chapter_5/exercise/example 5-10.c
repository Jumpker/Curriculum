#include<stdio.h>
#include<math.h>
#include<windows.h>
void main(){
	int f=1;
	float pi=0, t=1, v=1;
	while (fabs(t)>1e-6){
		pi += t;
		v += 2;
		f = -f;
		t = f/v;
	}
	pi *= 4;
	printf("\n pi = %10.8f",pi);
	
	system("pause");
}
