#include<stdio.h>
#include<windows.h>
#include<math.h>

void main(){
	unsigned int i, j, count, flag;		//��flag����־
	count = 0;							//����������
	for(i=3; i<= 1000; i++){
		flag = 0;
		for(j=2; j<=sqrt(i); j++)
			if (i%j == 0)				//������, ��������, ��־Ϊ1 
			{flag = 1; break;}			//��ѭ������ 
		if(flag == 0){						//��flagΪ0, i������ 
			printf("%4d,",i);
			count++;
			if(count % 8 == 0)
				printf("\n");					//���8����������
		}
	}
	system("pause");
}
