#include <stdio.h>
#include <stdlib.h>
int main() {
    int a;
    int b;
    printf("Molq vuvedete dve chisla: ");
    scanf("%d", &a);
    scanf("%d", &b);
    int sum = a + b;
    int diff = abs(a-b);
    int multiply = a*b;
    int del = a/b;
    printf("Sumata na chislata e: %d\n", sum);
    printf("Razlikata na chislata e: %d\n", diff);
    printf("Proizvedenieto na chislata e: %d\n", multiply);
    printf("Chastnoto na chislata e: %d", del);
    return 0;
}