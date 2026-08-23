#include <stdio.h>

int main() {
    int arr[7];
    int i;
    int sum = 0;
    printf("Enter 7 numbers: ");

    // Въвеждане на числата
    for (i = 0; i < 7; i++) {
        scanf("%d", &arr[i]);
    }

    // Сумиране
    for (i = 0; i < 7; i++) {
        sum = sum + arr[i];
    }

    // Извеждане на резултата
    printf("Sum = %d\n", sum);

    return 0;
}