#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter the number of elements for the array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("No memory!");
        return 1;
    }

    printf("Enter the numbers for the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int diff = max - min;
    printf("The biggest element of the array is: %d\n", max);
    printf("The smallest element of the array is: %d\n", min);
    printf("The diff of the elements is: %d", diff);

    free(arr);
    return 0;
}
