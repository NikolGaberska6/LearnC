#include <stdio.h>
int main () {
    int numbers[100];
    int sum = 0;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }

    printf("Sum of elements is: %d", sum);
    return 0;


}