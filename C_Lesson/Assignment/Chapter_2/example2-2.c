void main(){
	char c1, c2;					//定义字符型变量c1, c2 
	c1 = 'a';
	c2 = 'b';						//给c1、c2赋初值, c1、c2存储的是ASCII码, 分别为97和98
	c1 = c1 - 32;
	c2 = c2 - 32;					//c1 = c1 -32 和 c2 = c2 - 32是ASCII码相减 
	printf("%c %c",c1,c2);
}
