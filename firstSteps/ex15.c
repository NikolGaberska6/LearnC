#include <stdio.h>
int main() {

    char symbol;
    printf("Enter a symbol: ");
    scanf("%c", &symbol);

    int rows = 5;
    int columns = 10;

    for (int i = 1; i <= rows; i++) { //5 reda
        for (int j = 1; j <= columns; j++) { //10 koloni
            if (j == 1 || j == columns || i == 1 || i == rows) {
                printf("%c", symbol);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}