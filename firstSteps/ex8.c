#include <stdio.h>
int main() {
    int a,b,c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    int minNumber = a;
    if (b < minNumber) {
        minNumber = b;
    } else if (c < minNumber) {
        minNumber = c;
    }

    printf("The smallest number is: %d", minNumber);
}