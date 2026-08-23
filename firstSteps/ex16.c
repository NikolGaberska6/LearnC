#include <stdio.h>
int main() {
    int celsii;
    printf("Enter the degree you want to convert: ");
    scanf("%d", &celsii);

    int celsiiTOFahrenhait = celsii * 9/5 + 32;
    printf("Degree in Faherenhait is: %d", celsiiTOFahrenhait);

}