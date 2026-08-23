#include <stdio.h>
int main() {
    double priceKgVegetable;
    double priceKgFruits;
    int allKgVegetable;
    int allKgFruits;
    printf("Enter the price of each kg vegetable: ");
    scanf("%lf", &priceKgVegetable);
    printf("Enter the price of each kg fruits: ");
    scanf("%lf", &priceKgFruits);
    printf("Enter the kg of fruits: ");
    scanf("%d", &allKgVegetable);
    printf("Enter the kg of fruits: ");
    scanf("%d", &allKgFruits);

    double sumOfMoney = 0;
    double moneyInEuro = 1;
    sumOfMoney = priceKgVegetable * allKgVegetable + priceKgFruits * allKgFruits;
    printf("Full sum in lv is: %.2lf\n", sumOfMoney);
    moneyInEuro = sumOfMoney * 1.95;
    printf("Money in euro: %.2lf", moneyInEuro);
}