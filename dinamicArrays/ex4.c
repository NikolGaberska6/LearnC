#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m;
    printf("Enter the length for the first array: ");
    scanf("%d", &n);
    printf("Enter the length for the second array: ");
    scanf("%d", &m);

    int* arr1 = (int*)malloc(n * sizeof(int));
    int* arr2 = (int*)malloc(m * sizeof(int));

    if (arr1 == NULL || arr2 == NULL) {
        printf("No memory!");
        return 1;
    }

    printf("Enter the numbers for first array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the numbers for second array: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    int size = n + m;

    int* arr3 = (int*)malloc(size * sizeof(int));
    if (arr3 == NULL) {
        printf("No memory!");
        free(arr1);
        free(arr2);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr3[i] = arr1[i];
        //Копира първия масив в началото на arr3
        //arr1 = [10 20 30] --> n = 3
        //след цикъла: ---> arr3 = [10 20 30 _ _]
    }

    for (int i = 0; i < m; i++) {
        arr3[i + n] = arr2[i];
        //0 + 3 ----> [10 20 30 40 _ _]
        //1 + 3 ----> [10 20 30 40 50 _] etc.
    }

    // Сортиране (bubble sort)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr3[j] > arr3[j + 1]) {
                int temp = arr3[j];
                arr3[j] = arr3[j + 1];
                arr3[j + 1] = temp;
            }
        }
    }

    // Извеждане
    printf("Merged and sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr3[i]);
    }

    printf("\n");
    free(arr1);
    free(arr2);
    free(arr3);
    return 0;
}