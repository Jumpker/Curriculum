void main(){
	char c1, c2;					//�����ַ��ͱ���c1, c2 
	c1 = 'a';
	c2 = 'b';						//��c1��c2����ֵ, c1��c2�洢����ASCII��, �ֱ�Ϊ97��98
	c1 = c1 - 32;
	c2 = c2 - 32;					//c1 = c1 -32 �� c2 = c2 - 32��ASCII����� 
	printf("%c %c",c1,c2);
}
