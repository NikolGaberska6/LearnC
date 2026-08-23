#include <stdio.h>

double calculate(double number1, double number2, char operation) {
    switch (operation) {
        case '+': {
            double result = number1 + number2;
            return result;
        }
        case '-': {
            double result = number1 - number2;
            return result;
        }
        case '*': {
            double result = number1 * number2;
            return result;
        }
        case '/': {
            double result = number1 / number2;
            return result;
        }
        default: {
            return 0;
        }
    }
}
int main() {
    double number1, number2;
    char operation;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &number1, &number2);
    printf("Enter an operation: ");
    scanf(" %c", &operation);
    double result = calculate(number1, number2, operation);
    printf("The result of operator '%c' is: %.2f", operation, result);

}