#include<stdio.h>
#include<windows.h>

void main(){
	int year,leap;
	printf("�������: ");
	scanf("%d",&year);
	if (year%400 == 0){
		leap = 1;								//������ 
	}else{
		if (year%4 == 0 && year%100 != 0){
			leap = 1;							//������ 
		}else{
			leap = 0;							//�������� 
		}
	}
	if (leap == 1){
		printf("%d: ������",year);
	}else{
		printf("%d: ��������",year);
	} 
	system("pause");
}
