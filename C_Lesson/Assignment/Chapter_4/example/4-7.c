#include<stdio.h>
#include<windows.h>
#include<math.h>

void main(){
	float a,b,c,x1,x2,disc;
	printf("����a b c:");
	scanf("%f %f %f",&a,&b,&c);
	if (fabs(a) < 1e-6){											//a == 0; �����,��ʼ��֪��fabs()��� 
		printf("�÷��̲��Ƕ��η���");}							//�����Ǹ����,ȥ���˷����Ǿ���ֵ 
	else{ 
		disc = b*b - 4*a*c; 
		if(disc < 0){
			printf("�÷���û��ʵ��");}
		else{
			if (fabs(disc) < 1e-6){								//�б�ʽ����0
			printf("�÷�����������ȵ�ʵ��: %8.4f",-b/(2*a));} 
			else{
				x1 = (-b + sqrt(disc))/(2*a);
				x2 = (-b - sqrt(disc))/(2*a);
				printf("�÷�������������ʵ��: %8.4f��%8.4f",x1,x2);} 
			}
		}
	system("pause");
}
