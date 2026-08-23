#include <stdio.h>
int main() {
    int daysInMonth;
    printf("Enter the working days in month: ");
    scanf("%d", &daysInMonth);
    double moneyInUSD;
    printf("Enter money for day in usd: ");
    scanf("%lf", &moneyInUSD);
    double courseInLv;
    printf("Enter course in lv: ");
    scanf("%lf", &courseInLv);

    double moneyForMonth = daysInMonth * moneyInUSD;
    double bonus = moneyForMonth * 2.5;
    double moneyForYear = (moneyForMonth * 12) + bonus;
    double charge = 0.25 * moneyForYear;
    moneyForYear = moneyForYear - charge;
    double moneyForYearInLv = moneyForYear * courseInLv;
    double moneyForDay = moneyForYearInLv / 365;

    printf("Money for a day is: ");
    printf("%.2lf", moneyForDay);

}
