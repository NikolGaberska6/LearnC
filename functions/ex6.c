#include <stdio.h>

int countDigits(int number) {
    int count = 0;

    if (number == 0)
        return 1;

    if (number < 0)
        number = -number;

    while (number != 0) {
        number = number / 10;
        count++;
    }
    return count;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("The number of digits is: %d\n", countDigits(number));

    return 0;
}