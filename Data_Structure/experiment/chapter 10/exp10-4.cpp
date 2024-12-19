#include"seqlist.cpp"                                               //包含排序顺序表的基本运算算法

void BubbleSort(RecType R[], int n){                                //冒泡排序算法
    int i, j;
    bool exchange;
    for(i=0; i<n-1; i++){
        exchange = false;                                           //一趟前exchange置为假
        for(j=n-1; j>i; j--)                                        //归位R[i], 循环n-i-1次
        if (R[j].key < R[j-1].key){                                 //相邻两个元素反序时 
            swap(R[j], R[j-1]);                                     //交换位置
            exchange = true;                                        //一旦有交换, exchange置为真
        }
        printf("   i=%d：归位元素%d, 排序结果：", i, R[i].key);
        DispList(R, n);
        if (!exchange) return;                                      //本趟若无交换，中途结束算法
    }
}

int main(){
    int n=10;
    RecType R[MAXL];
    KeyType a[] = {6, 8, 7, 9, 0, 1, 3, 2, 4, 5};
    CreatList(R, a, n);
    printf("排序前：");     DispList(R, n);
    BubbleSort(R, n);
    printf("排序后：");     DispList(R, n);
    return 1;
}