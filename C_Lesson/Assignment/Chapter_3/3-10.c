#include"stdio.h"
#include<windows.h>

void main(){
	char ch;
	printf("Input a lowercase letter: ");
	ch = getchar();								//������ĸ����ch 
	printf("%4c%4c%4c\n",ch-1,ch,ch+1);			//���ch��ǰ�����ĸ
	//ÿ�����ݷֱ���"%4d %4o"���ָ�ʽ���
	printf("%4d %4o,%4d %4o,%4d %4o,\n\n",ch-1,ch-1,ch,ch,ch+1,ch+1);
	ch = ch - 32;								//��Сд��ĸת��Ϊ��Ӧ��д��ĸ
	printf("%4c %4c %4c\n",ch-1,ch,ch+1);		
	//chת���ɴ�д��ĸ��, �ظ�ǰ��������� 
	printf("%4d %4o,%4d %4o,%4d %4o,\n\n",ch-1,ch-1,ch,ch,ch+1,ch+1);
	system("pause");
}
