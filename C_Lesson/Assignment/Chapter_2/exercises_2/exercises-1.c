#include <stdio.h>

void main(){
	int x,y,z;
	x=y=1;
	
	z=x++, y++, ++y;				//这里使用了x++, 所以x已经是2了
									//而y经历了两次++, 已经变成了3 
									//x++表示x在+1前的值, 所以此时z等于原来的x的值, 即1 
	printf("%d,%d,%d\n",x,y,z);
 } 
