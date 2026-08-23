#include <stdio.h>
int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    if (year % 4 == 0 && year % 100 != 0) {
        printf("Godinata e visokosna!");
    } else if (year % 400 == 0) {
        printf("Godinata e visokosna!");
    } else {
        printf("Godinata ne e visokosna!");
    }

}
