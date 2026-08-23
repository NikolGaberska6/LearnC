#include <stdio.h>
#include <string.h>
// int main() {
//     int number;
//     printf("Enter a number: ");
//     scanf("%d", &number);
//
//     int newNumber = 0;
//     printf("Reversed number: ");
//     while (number != 0) {
//         newNumber = number % 10;
//         printf("%d", newNumber);
//         number = number /10;
//     }
// }

int main() {
    char number[100];  //"1", "2", "3", "4"
    printf("Enter a number: ");
    scanf("%s", number);

    int len = strlen(number);
    printf("Reversed number is: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", number[i]);
    }

    return 0;
}