#include "seqlist.cpp"                                          //包含顺序表基本运算算法
int BinSearch(RecType R[], int n, KeyType k){                   //折半查找算法
    int low=0, high=n-1, mid, count=0;
    while (low <= high){
        mid = (low+high)/2;
        printf("第%d次比较: 在[%d, %d]中比较元素R[%d]: %d\n",
            ++count, low, high, mid, R[mid].key);
        if(R[mid].key == k)                                     //查找成功返回
            return mid+1;
        if(R[mid].key > k)                                      //继续在R[low..mid-1]中查找
            high = mid-1;
        else                                                    //继续在R[mid+1..high]中查找
            low = mid+1;
    }
    return -1;
}

int BinInsort(RecType R[], int n, KeyType k){                  //折半插入排序算法
    int i;
    if((i=BinSearch(R, n, k)) != -1){
        printf("元素%d已在表中, 位置是%d\n", k, i);
        return -1;
    }else{                                                      //插入元素k
        int low = 0, high = n - 1, mid;
        while (low <= high) {                                   //折半查找插入位置
            mid = (low + high) / 2;
            if (R[mid].key < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        for(i=n-1; i>= low; i--)                                //进行插入
            R[i+1] = R[i];                                      //元素后移
        R[low].key = k;
        printf("插入元素%d成功\n现在的关键字序列为: ", k); DispList(R, n+1);
        return 0;
    }
}

int BinDelete(RecType R[], int n, KeyType k){
    int i;
    if((i=BinSearch(R, n, k)) != -1){
        for(; i<n; i++)                                         //进行删除
            R[i-1] = R[i];                                      //元素前移
        printf("删除元素%d成功\n现在的关键字序列为: ", k); DispList(R, n-1);
        return 0;
    }
    else{
        printf("元素%d不在表中\n", k);
        return -1;
    }
}

int main(){
    RecType R[MAXL];
    KeyType k = 6;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i, n=10;
    CreateList(R, a, n);                                        //创建顺序表
    printf("关键字序列: "); DispList(R, n);
    printf("查找%d的比较过程如下: \n", k);
    if((i=BinSearch(R, n, k)) != -1)
        printf("元素%d的位置是%d\n", k, i);
    else
        printf("元素%d不在表中\n", k);

    printf("\n现在插入元素%d: \n", k); 
    if(BinInsort(R, n, k) != -1) n++;

    printf("\n现在删除元素%d: \n", k); 
    if(BinDelete(R, n, k) != -1) n--;
    return 1;
} 