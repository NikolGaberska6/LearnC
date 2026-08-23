#include <stdio.h>
int main() {
    int number;
    int sum = 0;

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &number);
        if (number == 0) {
            break;
        }
        sum += number;
    }
    printf("The sum of numbers is: %d", sum);
    return 0;
}

// int main() {
//     int numNumbers;
//     printf("Enter the num of numbers: ");
//     scanf("%d", &numNumbers);
//
//     int sum = 0;
//
//     for (int i = 1; i <= numNumbers; i++) {
//         printf("Enter a number:");
//         int number;
//         scanf("%d", &number);
//         if (number == 0) {
//             break;
//         } else {
//             sum += number;
//         }
//
//     }
//
//     printf("The sum of numbers is: %d", sum);
// }

