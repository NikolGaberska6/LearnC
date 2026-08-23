#include <stdio.h>
// int main () {
//     int number; //123
//     printf("Enter a number: ");
//     scanf("%d", &number);
//
//     int d1 = number % 10; //3
//     number = number / 10; //12
//     int d2 = number % 10; //2
//     number = number / 10; //1
//     int d3 = number % 10; // 1
//     number = number / 10; //0
//     int sumOfDigits = d1 + d2 + d3;
//     printf("Sum of digits: %d", sumOfDigits);
// }

// int main () {
//     int number;
//     int sum = 0;
//     printf("Enter a number: ");
//     scanf("%d", &number);
//
//     for (int i = 0; i < 4; i++) {
//         sum += number % 10;
//         number = number / 10;
//     }
//
//     printf("Sum of digits is: %d", sum);
// }

int main() {
    int number; //1234
    int sum = 0;
    printf("Enter a number: ");
    scanf("%d", &number);

    while (number != 0) {
        sum = sum + number % 10; //4
        number = number / 10; //123
    }
    printf("Sum of digits is: %d", sum);
}


