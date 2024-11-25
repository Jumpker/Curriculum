#include<stdio.h>
#include<windows.h>

int cton(){                                             //读入字符转换成数字
    char ch;
    int n=0, f=0, n1=0;
    while((ch=getchar())<='0' || ch>='9'){
        n1++;                                           //非数字字符, 用n1计数
        if(n1 >= 10){
            printf("data is wrong !"); return 0;        //输入超过10个非数字的字符
        }
    }
    do{
        n = n*10 + ch - '0';                            //将字符转换成数字
    }while ((ch=getchar())>='0' && ch<='9');            //输入了非数字字符, 结束输入
    return n;
}

void main(){
    int m;
    printf("input m: ");
    m = cton();
    printf("\n m = %d\n", m);
    system("pause");
}