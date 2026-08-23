#include <stdio.h>
int main() {
    int arr[7];
    printf("Enter 7 numbers: ");

    for (int i = 0; i < 7; i++) {
        scanf("%d", &arr[i]); //1 2 3 4 5 6
    }

    for(int i = 0; i < 6; i++) { // 1 2 3 4 5 6
        for(int j = 0; j < 6 - i; j++) { //
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}