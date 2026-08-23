#include <stdio.h>
int main() {
    double lev;
    printf("Enter a value for lev: ");
    scanf("%lf", &lev);

    double usd = lev * 0.55;
    double eur = lev * 0.51;
    double gbr = lev * 0.44;

    printf("The value of %.2lf lv is: ", lev);
    printf("%.2lf USD %.2lf EUR %.2lf GBR", usd, eur, gbr);
}