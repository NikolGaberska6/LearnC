#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int arr[n][n];
    // Въвеждане на елементите на матрицата
    printf("Enter the elements of matrix: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    //Главен диагонал
    printf("Main diagonal:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i][i]);
    }


    // b) Второстепенен диагонал
    printf("\nSecondary diagonal: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i][n - i - 1]);
    }

    // c) Над главния диагонал
    printf("\nAbove main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
    }

    // d) Под главния диагонал
    printf("\nBelow main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", arr[i][j]);
        }
    }

    printf("\n");

    return 0;

}