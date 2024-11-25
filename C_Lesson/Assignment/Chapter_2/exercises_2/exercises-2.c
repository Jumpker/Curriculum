#include <stdio.h>

void main()
{
	int i,j;
	i=8, j=10;
	printf("%d,%d,%d,%d\n",i,j,++i,j++);
}
	//在这个printf中, i和j都分别经历了一次++, 所以i和j的值都加一, 分别变成9和11
	//++i表示i+1后的值, 所以是9
	//j++表示j+1前的值, 所以是10 
