#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter the three sides:  ");
    scanf("%d %d %d", &a, &b, &c);

    if (a+b > c && a+c > b && b+c > a) {
        printf("It can be thriagle!");
        if (a == b && b == c && c == a) {
            printf("Triugulnika e ravnostranen!");
        } else if (a != b && b != c && c != a) {
            printf("Triugulnika e raznostranen!");
        } else {
            printf("Triugulnika e razvnobedren!");
        }
    } else {
        printf("It cannot be triangle!");
    }
}