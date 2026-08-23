#include <stdio.h>
#include <stdlib.h>
int main () {
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int* arr1 = (int*)malloc(n * sizeof(int));
    if (arr1 == NULL) {
        printf("No memory!");
        return 1;
    }

    printf("Enter the elements of the array: ");
    for (int i= 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    // Първо броим колко са четните числа
    int countEven = 0;
    for (int i = 0; i < n; i++) {
        if (arr1[i] % 2 == 0) {
            countEven ++;
        }
    }

    // Създаваме нов масив за четните
    int* arr2 = (int*)malloc(countEven * sizeof(int));
    if (arr2 == NULL) {
        printf("No memory!");
        free(arr1);
        return 1;
    }

    // Копиране на четните числа
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr1[i] % 2 == 0) {
            arr2[j] = arr1[i];
            j++;
        }
    }

    printf("Even numbers are: ");
    for (int i = 0; i < countEven; i++) {
        printf("%d ", arr2[i]);
    }

    free(arr1);
    free(arr2);
    return 0;

}