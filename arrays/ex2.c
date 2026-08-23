#include <stdio.h>
int main() {
    int arr[7];
    int max = arr[0];
    printf("Enter 7 numbers: ");

    for (int i = 0; i < 7; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 7; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Max number is: %d", max);
}