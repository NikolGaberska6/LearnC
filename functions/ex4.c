#include <stdio.h>

int evenOrOdd(int number) {
    if (number % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (evenOrOdd(number)) {
        printf("Number is even");
    } else {
        printf("Number is odd");
    }
    return 0;
}