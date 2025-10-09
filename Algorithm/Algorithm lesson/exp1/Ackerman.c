#include <stdio.h>
#include <stdlib.h>

int ackerman(int n, int m) {
    if (n==1 && m==0) {
        return 2;
    } else if (n==0 && m>=0) {
        return 1;
    } else if (n>=2 && m==0) {
        return n+2;
    } else if(n>=1 && m>=1) {
        return ackerman(ackerman(n-1, m), m-1);
    }
}

int main() {
    printf("%d\n", ackerman(2, 2));
    printf("%d\n", ackerman(4, 3));
    printf("%d\n", ackerman(5, 3));
    printf("%d\n", ackerman(5, 4));
    return 0;
}