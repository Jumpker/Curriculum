#include<stdio.h>
#include"math.h"

void main(){
	float a,b,c,disc,x1,x2;
	printf("Input a,b,c: ");
	scanf("%f,%f,%f",&a,&b,&c);
	disc = b*b - 4*a*c;
	x1 = (-b + sqrt(disc))/(2*a);
	x2 = (-b - sqrt(disc))/(2*a);
	printf("\nx1 = %6.2f\nx2 = %6.2f\n",x1,x2);
} 
