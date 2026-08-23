#include <stdio.h>

int isPrime(int number) {
    if (number < 0) {
        return 0;
    }

    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (isPrime(number)) {
        printf("It is a prime number!\n");
    } else {
        printf("It is not a prime number!\n");
    }

}