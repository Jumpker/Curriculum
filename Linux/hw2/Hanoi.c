#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char start, char end, char temp) {
    if (n == 1) {
        printf("%c->%c\n", start, end);
        return;
    }
    hanoi(n-1, start, temp, end);
    printf("%c->%c\n", start, end);
    hanoi(n-1, temp, end, start);
}

void main() {
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
}