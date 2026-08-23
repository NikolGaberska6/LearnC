#include <stdio.h>
int main() {
    int number1;
    int number2;
    printf("Enter the first number: ");
    scanf("%d", &number1);
    printf("Enter the second number: ");
    scanf("%d", &number2);

    int sum = 0;
    for (int i = number1 + 1; i < number2; i++ ) {
        sum += i;
    }

    printf("Sum is: %d", sum);
}