#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Enter two numbers: ");
    scanf("%d", &n);
    scanf("%d", &m);

    // Заделяне на памет
    int* arr1 = (int*)malloc(n * sizeof(int));
    int* arr2 = (int*)malloc(m * sizeof(int));

    if (arr1 == NULL || arr2 == NULL) {
        printf("No memory!\n");
        return 1;
    }

    // Въвеждане на първия масив
    printf("Enter the numbers for first array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    // Въвеждане на втория масив
    printf("Enter the numbers for second array: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    int sum = 0;

    // Сумиране на първия масив
    for (int i = 0; i < n; i++) {
        sum += arr1[i];
    }

    // Сумиране на втория масив
    for (int i = 0; i < m; i++) {
        sum += arr2[i];
    }

    double average = (double)sum / (n + m);

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    // Освобождаване на памет
    free(arr1);
    free(arr2);

    return 0;
}