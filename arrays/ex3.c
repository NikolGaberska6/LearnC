#include <stdio.h>

int main () {
    int arr[7];
    double average;
    double sum = 0.0;
    printf("Enter 7 numbers: ");

    for (int i = 0; i < 7; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 7; i++) {
        sum += arr[i];
    }

    average = sum / 7.0;
    printf("The average is %.3f", average);

    return 0;
}