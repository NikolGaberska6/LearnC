#include <stdio.h>

int sumOfDigits (int number) {
    int sum = 0;

    if (number < 0) {
        number = -number;
    }

    while (number > 0) {
        sum += number % 10; //dava poslednoto chislo
        number = number / 10; //maha poslednoto chislo
    }
    return sum;
}

int main() {
    printf("Enter a number: ");
    int number;
    scanf("%d", &number);
    printf("Sum of digits is: %d", sumOfDigits(number));
}