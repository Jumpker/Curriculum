#include<stdio.h>
#include<windows.h>
#include<math.h>

void main(){
	unsigned int i, j, count, flag;		//用flag做标志
	count = 0;							//计数器清零
	for(i=3; i<= 1000; i++){
		flag = 0;
		for(j=2; j<=sqrt(i); j++)
			if (i%j == 0)				//能整除, 不是素数, 标志为1 
			{flag = 1; break;}			//内循环结束 
		if(flag == 0){						//若flag为0, i是素数 
			printf("%4d,",i);
			count++;
			if(count % 8 == 0)
				printf("\n");					//输出8个素数换行
		}
	}
	system("pause");
}
