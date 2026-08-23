#include <stdio.h>
// int main() {
//     int a, b, c;
//     printf("Enter three numbers: ");
//     scanf("%d %d %d", &a, &b, &c);
//
//     int minNumber = a;
//     if (b < minNumber) {
//         minNumber = b;
//     } else if (c < minNumber) {
//         minNumber = c;
//     }
//
//     printf("Min number is: %d", minNumber);
// }

int main () {
    int numNumbers;
    int newNum;
    int maxNumber;
    printf("Enter the number of numbers: ");
    scanf("%d", &numNumbers);

    for (int i = 0; i < numNumbers; i++ ) {
        printf("Enter a number: ");
        scanf("%d", &newNum);

        if (i == 0 || newNum > maxNumber) {
            maxNumber = newNum;
        }
    }

    printf("The maximum number is %d\n.", maxNumber);
}