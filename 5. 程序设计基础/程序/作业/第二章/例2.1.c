void main(){
	int x,y,z,w;			//定义x,y,z,w为整形变量
	unsigned int k;			//定义k为无符号整型变量
	x = 10;
	y = -20;
	k = 30;
	z = x + k;
	w = y + k;				//不同类型的整形变量x、y、k可运算
	printf("x+k=%d, y+k=%d\n",z,w); 
}
