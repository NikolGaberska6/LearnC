#include <stdio.h>
int main() {
    int number1; //10
    printf("Enter the first number: ");
    scanf("%d", &number1);
    int number2; //2
    printf("Enter the second number: ");
    scanf("%d", &number2);
    int sumOfEven = 0;
    int multyOfOdd = 1;

    int start, end;

    if (number1 < number2) {
        start = number1;
        end = number2;
    } else {
        start = number2;
        end = number1;
    }

    for (int i = start + 1; i < end; i++) {
        if (i % 2 == 0) {
            sumOfEven += i;
        } else {
            multyOfOdd *= i;
        }
    }

    printf("Sum of ecven: %d", sumOfEven);
    printf("\n");
    printf("Multy of odd: %d", multyOfOdd);

    return 0;
}
