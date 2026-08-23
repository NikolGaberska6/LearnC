#include <stdio.h>
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number % 8 > 4) {
        printf("The number %d is divisible by 8\n", number);
    } else {
        printf("no\n");
    }
}