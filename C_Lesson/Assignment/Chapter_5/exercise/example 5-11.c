#include<stdio.h>
#include<windows.h>

void main(){
	char ch;
	while ((ch=getchar()) != '\n'){
		//ch����ĸʱ
		if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
			if((ch>='w' && ch<='z') || (ch>='W' && ch<='Z'))
			//ch����ĸw, x, y, z��W, X, Y, Z
				ch -= 26;			//����Խ�� 
			ch += 4;	 			//���м��ܴ��� 
		}
		printf("%c",ch);			//������ܺ�ĵ��� 
	}
	printf("\n");
	system("pause");
}
