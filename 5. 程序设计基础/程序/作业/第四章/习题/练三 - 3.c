#include<stdio.h>

void main(){
	int x=1, y=2, z=3;
	if(x--)						//x--得到的值为1, 故执行y++和z++ 
		y++, z++;				//经过这个语句后, x=0, y=3, z=4 
	else
		y--;
		z--;					//这里z又-1, 因此z=3 
	printf("%d,%d,%d\n",x,y,z);
} 
