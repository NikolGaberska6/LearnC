#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Medicine {
    char name[31];
    char date[8];
    long long code;
    double price;
    int quantity;
};

/* ===== ЗАДАЧА 2: цена ===== */
void update_medicine_price(struct Medicine medicines[], int count, char date[]) {
    int targetMonth;
    int targetYear;
    sscanf(date, "%d.%d", &targetMonth, &targetYear);

    int counter = 0;
    for (int i = 0; i < count; i++) {
        int m, y;
        sscanf(medicines[i].date, "%d.%d", &m, &y);
        //👉 Взима датата на конкретното лекарство от масива
        if (y < targetYear || (y == targetYear && m < targetMonth)) {
            counter++;
            double oldPrice = medicines[i].price;
            medicines[i].price *= 0.8;
            printf("%s - %s - %.2lf lv - %.2lf lv", medicines[i].name,
                medicines[i].date, oldPrice, medicines[i].price);
        }
    }
    if (counter == 0) {
        printf("No medicines to change!");
    }
}

/* ===== ЗАДАЧА 3: количество ===== */
void writeOfferBin (struct Medicine medicines[], int count, int minQuantity) {
    FILE *file = fopen("offer.bin", "wb");
    if (file == NULL) {
        printf("Error opening file!");
        return;
    }
    for (int i = 0; i < count; i++) {
        if (medicines[i].quantity > minQuantity) {

            int len = strlen(medicines[i].name);

            if (fwrite(&len, sizeof(int), 1, file) != 1 ||
                fwrite(medicines[i].name, sizeof(char), len, file) != (size_t)len ||
                fwrite(medicines[i].date, sizeof(char), 8, file) != 8 ||
                fwrite(&medicines[i].code, sizeof(long long), 1, file) != 1 ||
                fwrite(&medicines[i].price, sizeof(double), 1, file) != 1 ||
                fwrite(&medicines[i].quantity, sizeof(int), 1, file) != 1) {

                printf("Write error!\n");
                fclose(file);
                return;
                }
        }
    }
    fclose(file);
}

/* ===== ЗАДАЧА 4: изтриване ===== */
void deleteElement(struct Medicine medicines[], int *count, long long code) {

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (medicines[i].code == code) {
            found = 1;
            // местим елементите наляво
            for (int j = i; j < *count - 1; j++ ) {
                medicines[j] = medicines[j + 1];
            }
            (*count)--;
            printf("Deleted medicine!");
            return;
        }
    }

    if (found == 0) {
        printf("No medicines found!");
    }

}

int main () {

    FILE *file = fopen("medicine.txt", "r");
    if (file == NULL) {
        printf("Error opening file!");
        return 1;
    }

    int count = 0;
    char ch;
    // 1. Броене на редовете (лекарствата) във файла
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    rewind(file);
    // 3. Динамично заделяне на масива веднага със стойност
    struct Medicine *medicines = (struct Medicine *)malloc(count * sizeof(struct Medicine));
    if (medicines == NULL) {
        printf("Error allocating memory!");
        fclose(file);
        return 1;
    }
    //4. Зареждане на данните в масива
    for (int i = 0; i < count; i++) {
        fscanf(file, " %30[^;]; %7[^;]; %lld; %lf; %d\n",
            medicines[i].name, medicines[i].date, &medicines[i].code,
            &medicines[i].price, &medicines[i].quantity);
    }
    fclose(file);

    /*
       ЗАДАЧА 2 – обработка на цени
   */
    char inputDate[8];
    printf("Enter date (MM.YYYY): ");
    scanf("%7s", inputDate);
    update_medicine_price(medicines, count, inputDate);

    /*
       ЗАДАЧА 3 – запис в бинарен файл
   */
    int minQuantity;
    printf("Enter the minimum quantity: ");
    scanf("%d", &minQuantity);
    writeOfferBin(medicines, count, minQuantity);

    /*
       ЗАДАЧА 4 – изтриване на лекарство
   */
    long long code;
    printf("Enter the code: ");
    scanf("%lld", &code);
    deleteElement(medicines, &count, code);

    /*
        Освобождаване на паметта
    */
    free(medicines);

    return 0;

}