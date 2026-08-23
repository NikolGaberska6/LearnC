#include <stdio.h>
int main() {
    int N;
    int K;
    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter K: ");
    scanf("%d", &K);
    int biggestThanK = 0;

    for (int i = 1; i <= N; i++) {
        int number;
        printf("Enter number: ");
        scanf("%d", &number);
        if (number > K && number % 3 == 0) {
            biggestThanK += 1;
        }
    }
    printf("Num of numbers bigger than K is %d", biggestThanK);
}