#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[31];
    char date[8];
    long long code;
    double price;
    int quantity;
};

/* ===== ЗАДАЧА 2 ===== */
struct Medicine* filterMedicine(struct Medicine medicines[], int count, char date[]) {
    int giveMonth;
    int givenYear;
    sscanf(date,"%d.%d", &giveMonth, &givenYear);

    struct Medicine *result = (struct Medicine*)malloc(count * sizeof(struct Medicine));
    if (result == NULL) {
        printf("Error allocating memory!");
        exit(1);
    }

    int counter = 0;
    for (int i = 0; i < count; i++) {
        int medicineM;
        int medicineY;
        sscanf(medicines[i].date, "%d.%d", &medicineM, &medicineY);
        if (medicineY < givenYear || (medicineY == givenYear && medicineM < giveMonth)) {
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

/* ===== ЗАДАЧА 3 ===== */
int writeOffers(struct Medicine medicines[], int count, double minPrice, double maxPrice) {
    FILE *file = fopen("offer.txt", "w");
    if (file == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    int countEl = 0;
    for (int i = 0; i < count; i++) {
        if (medicines[i].price >= minPrice && medicines[i].price <= maxPrice) {
            fprintf(file, "%s\n", medicines[i].name);
            fprintf(file, "%s\n", medicines[i].date);
            fprintf(file, "%lld\n", medicines[i].code);
            fprintf(file, "%.2lf leva\n", medicines[i].price);
            countEl++;
        }
    }
    if (countEl == 0) {
        return 0;
    }

    fclose(file);
    return countEl;
}

/* ===== ЗАДАЧА 4 ===== */
void deleteMedicine(struct Medicine medicines[], int *count, char name[], char date[]) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(medicines[i].name, name) == 0 &&
            (strcmp(medicines[i].date, date) == 0)) {
            for (int j = i; j < *count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            *count = *count - 1;
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Medicine not found!");
    }
}


int main() {
    FILE *file = fopen("medicines.bin", "rb");
    if (file == NULL) {
        printf("Error opening file: ");
        exit(1);
    }

    int count = 0;
    fseek(file, 0, SEEK_END);
    count = ftell(file) / sizeof(struct Medicine);
    rewind(file);

    struct Medicine *medicines = (struct Medicine *)malloc(count * sizeof(struct Medicine));
    if (medicines == NULL) {
        printf("Error allocating memory!");
        fclose(file);
        exit(1);
    }

    if (fread(medicines, sizeof(struct Medicine), count, file) != count) {
        printf("Error reading file!");
        fclose(file);
        exit(1);
    }
    fclose(file);

    /*
      ЗАДАЧА 2
  */
    char date[8];
    printf("Enter date: ");
    scanf("%7s", date);
    struct Medicine *result = filterMedicine(medicines, count, date);
    if (result == NULL) {
        printf("Error allocating memory!");
    }
    fclose(file);

    /*
      ЗАДАЧА 3
  */
    double minPrice;
    double maxPrice;
    printf("Enter the min price: ");
    scanf("%lf", &minPrice);
    printf("Enter the max price: ");
    scanf("%lf", &maxPrice);
    writeOffers(medicines, count, minPrice, maxPrice);

    /*
    ЗАДАЧА 4
    */
    char name[31];
    char givenDate[8];
    printf("Enter the medicine name: ");
    scanf("30%s", name);
    printf("Enter the medicine date (MM.YYYY): ");
    scanf("%7s", givenDate);
    deleteMedicine(medicines, &count, name, givenDate);

    free(medicines);

    return 0;
}