#include<stdio.h>
#include<windows.h>

void main(){
	char ch;
	while ((ch=getchar()) != '\n'){
		//ch是字母时
		if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
			if((ch>='w' && ch<='z') || (ch>='W' && ch<='Z'))
			//ch是字母w, x, y, z或W, X, Y, Z
				ch -= 26;			//消除越界 
			ch += 4;	 			//进行加密处理 
		}
		printf("%c",ch);			//输出加密后的电文 
	}
	printf("\n");
	system("pause");
}
