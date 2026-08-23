#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,m;
    char choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Заделяне на първоначална памет
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("No memory!");
        return 1;
    }

    //Въвеждане на елементите в масива
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Питаме дали иска разширение
    printf("Do you want to add more elements? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        printf("Enter the number of elements: ");
        scanf("%d", &m);
    }

    // Разширяване на масива
    int* temp = (int*)realloc(arr, (n + m)  * sizeof(int));

    if (temp == NULL) {
        printf("No memory!");
        free(arr);
        return 1;
    }

    arr = temp;
    //👉 Копира адреса, който е в temp, в arr
    //➡️ След това:
    //arr сочи към новия (или разширения) масив
    //старият адрес вече не ни трябва

    // Въвеждане на новите елементи
    printf("Enter the new elements to the array: ");
    for (int i = n; i < m + n; i++) {
        scanf("%d", &arr[i]);
    }
    //🔹 Защо започваме от i = n?
    //i = 0 до n-1 → вече са заети (старите числа)
    //i = n → първото свободно място
    //i < n + m → до края на новия размер

    n = n + m;
    //👉 n вече НЕ е актуален
    //👉 реалният размер на масива е n + m
    //🧠 Най-просто: обновяваш "официалния размер" на масива

    // Извеждане на крайния масив
    printf("Final array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);
    return 0;
}