#include<stdio.h>
#include<math.h>

void main(){
	double a,x,y;
	printf("������������λС��a��x, �м��ÿո����\n");
	scanf("%lf %lf",&a,&x); 
	if(fabs(x) == a){
		y = 0;
		printf("�õ��Ľ��Ϊ: %8.2lf",y);}
	else{
		if(fabs(a) == x)
			printf("��ѧ����! ln(x)��x����С�ڵ���0!"); 
		else if(x == a)
			printf("��ѧ����! ��ĸ����Ϊ0!");
		else{
		y = (log(fabs((a+x)/(a-x)))) / (2*a);
		printf("�õ��Ľ��Ϊ: %8.2lf",y);
		}
	}
}
