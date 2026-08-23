#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, number;
    printf("Enter the number of array: ");
    scanf("%d", &n);

    //Дефиниране на динамичния масив
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("No memory!");
        return 1;
    }

    //Въвеждане на елементите в масива
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element for remove: "); //20
    scanf("%d", &number);

    int found = 0;
    for (int i = 0; i < n; i++) { // 10 20 30 40 50 ---> 5 elements
        if (arr[i] == number) { //arr[1] = 20
            found = 1;
            for (int j = i; j < n - 1; j++) { // j = 1 ; j < 4; j++
                arr[j] = arr[j + 1];
                //10 30 30 40 50
                //10 30 40 40 50
                //10 30 40 50 50
            }
            n--; // 10 30 40 50
            i--; // i = 3
        }
    }

    if (!found) {
        printf("Number not found!");
    }

    // свиване на паметта
    int* temp = (int*)realloc(arr, n * sizeof(int));
    if (temp == NULL) {
        printf("No memory!");
        return 1;
    }

    arr = temp;

    // извеждане
    printf("Final array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}