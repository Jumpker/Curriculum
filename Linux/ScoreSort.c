#include <stdio.h>
#include <string.h>

void ScoreSort(char name[][20], int *score, int n){
    int outScore[20];
    char outName[20][20];
    int max;
    for(int i=0,k=0; i<n; i++,k++){
        max = i;
        for(int j=i+1; j<n; j++){
            if(score[j] > score[max]){
                max = j;
            }
            else if(score[j] == score[i]){
                for(int k=0; k<20; k++){                //同分，名字按字典序排序
                    if(name[j][k] == '\0'){
                        break;
                    }
                    if(name[j][k] < name[max][k]){
                        max = j;
                        break;
                    }
                    if(name[j][k] > name[max][k]){
                        break;
                    }
                }
            }
        }
        outScore[k] = score[max];       // 将最高分的分数放入outScore
        for(int j=0; j<20; j++){        // 将最高分的名字放入outName
            outName[k][j] = name[max][j];
        }
        score[max] = -1;                // 将最高分的分数设为-1
        if(max != i) i--;
    }
    for(int i=0; i<n; i++){             //输出
        printf("%s %d\n", outName[i], outScore[i]);
    }
}

void main(){
    int n;
    scanf("%d", &n);
    char name[n][20];
    int score[n];
    for(int i=0; i<n; i++){
        getchar();
        for(int j=0; j<20; j++){
            scanf("%c", &name[i][j]);
            if(name[i][j] == ' '){
                name[i][j] = '\0';
                break;
            }
        }
        scanf("%d", &score[i]);
    }
    ScoreSort(name, score, n);
    return 0;
}