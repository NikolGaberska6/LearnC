#include <stdio.h>

int sumOfDigits(int number) {
    int sum = 0;
    while (number != 0) {
        sum = sum + number % 10;
        number = number / 10;
    }
    return sum;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Sum of digits is: %d", sumOfDigits(number));

}