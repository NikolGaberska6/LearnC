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

/* ===== ЗАДАЧА 2: филтриране ===== */
struct Medicine* filterMedicine(struct Medicine medicines[], int count, char date[]) {
    int targetMonth; //MM
    int targetYear; //YYYY
    printf("Enter the month and the year: ");
    sscanf(date, "%d.%d", &targetMonth, &targetYear);
    struct Medicine *result = (struct Medicine*)malloc(count * sizeof(struct Medicine));
    if (result == NULL) {
        printf("Memory allocation error!");
        exit(1);
    }

    int counter = 0;
    for (int i = 0; i < count; i++) {
        int m, y;
        sscanf(medicines[i].date, "%d.%d", &m, &y);
        if (y < targetYear || (y == targetYear && m < targetMonth)) {
            result[counter] = medicines[i];
            counter++;
        }
    }
    if (counter == 0) {
        free(result);
        return NULL;
    }
    return result;
}

/* ===== ЗАДАЧА 3: запис във файл ===== */
int writeOffers(struct Medicine medicines[], int count, double maxPrice, double minPrice) {
    FILE *file = fopen("offer.txt", "w");
    if (file == NULL) {
        printf("File open error!");
        exit(1);
    }
    int counter = 0;
    for (int i = 0; i < count; i++) {
        if (medicines[i].price >= minPrice && medicines[i].price <= maxPrice) {
            fprintf(file, "%s\n", medicines[i].name);
            fprintf(file, "%s\n", medicines[i].date);
            fprintf(file, "%lld\n", medicines[i].code);
            fprintf(file, "%.2f leva\n\n", medicines[i].price);
            counter++;
        }
    }
    fclose(file);
    return counter;
}

/* ===== ЗАДАЧА 4: изтриване на лекарство ===== */
void deleteMedicine(struct Medicine medicines[], int *count, char name[], char date[]) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(medicines[i].name, name) == 0 &&
            strcmp(medicines[i].date, date) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            *count = *count - 1;
            break;
        }
    }
    if (found == 0) {
        printf("No medicine found with this date and name!");
    }
}

int main() {
    FILE *file = fopen("medicines.bin", "rb");
    if (file == NULL) {
        printf("Cannot open the file!");
        exit(1);
    }

    int count;
    /* местим курсора в края */
    fseek(file, 0, SEEK_END);
    /* намираме колко структури има */
    count = ftell(file) / sizeof(struct Medicine);
    /* връщаме се в началото */
    rewind(file);

    /* динамичен масив */
    struct Medicine *medicines = (struct Medicine *)malloc(count * sizeof(struct Medicine));
    if (medicines == NULL) {
        printf("Memory allocation error!");
        exit(1);
    }

    if (fread(medicines, sizeof(struct Medicine), count, file) != count) {
        printf("File read error!");
        exit(1);
    }

    /*
      ЗАДАЧА 2 – филтриране
  */
    char inputDate[8];
    printf("Enter date (MM.YYYY): ");
    scanf("%7s", inputDate);
    struct Medicine *result = filterMedicine(medicines, count, inputDate);
    if (result == NULL) {
        printf("No expired medicines found!");
    }
    free(result);

    /*
      ЗАДАЧА 3 – запис във файл
  */
    double minPrice, maxPrice;
    printf("Enter min and max price: ");
    scanf("%lf %lf", &minPrice, &maxPrice);
    writeOffers(medicines, count, minPrice, maxPrice);


    /*
    ЗАДАЧА 4 – изтриване на елемент
    */
    char name[31];
    char date[8];
    printf("Enter the medicine name: ");
    scanf("30%s", name);
    printf("Enter the medicine date (MM.YYYY): ");
    scanf("%7s", date);
    deleteMedicine(medicines, &count, name, date);


    free(medicines);
    return 0;

}