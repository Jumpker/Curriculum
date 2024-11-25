#include<stdio.h>

int qiuyinzi_iswanshu(int num){                    //求num的因子(包括它自己)
    int i, count=0, j=0, flag=0, sum=0;
    if(num <= 0) printf("输入错误");

    for(i=1; i<=num; i++){                          //判断数组长度(count)
        if(num%i == 0){
            count++;
        }
    }
//-----------求因子数组--------------------------
    int yinzi[count];                               //因为不判断因子一共有多少就无法确定数组的长度
    for(i=1; i<=num; i++){                          //所以在此时先用一个变量记录因子的个数，再定义数组
        if(num%i == 0){                             //或者可以考虑动态数组, 但是好像要学到后面指针先
            yinzi[j] = i;                           //现在这样大概相当于用时间复杂度换空间复杂度了
            j++;
        }
    }

//---------判断是否为完数-------------------------
    for(i=0; i<count-1; i++){
        sum += yinzi[i];
    }
    if(sum == num){
        flag = 1;
    }

//---------输出结果----------------------------
    if(flag == 1){
        printf("%d=", num);
        for(i=0; i<count-2; i++){
            printf("%d+", yinzi[i]);
        }
        printf("%d\n", yinzi[count-2]);
    }else{
        return 0;
    }
}

void main(){
    for (int i=1; i<=500; i++)
        qiuyinzi_iswanshu(i);
}