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

/* ===== ЗАДАЧА 2: промяна на цената ===== */
void changePrice(struct Medicine medicines[], int count, char date[]) {
    int givenMonth; //MM
    int givenYear; //YYYY
    sscanf(date, "%d.%d", &givenMonth, &givenYear); //MM.YYYY

    int medicinesChanged = 0;
    for (int i = 0; i < count; i++) {
        int monthOfMed;
        int yearOfMed;
        sscanf(medicines[i].date, "%d.%d", &monthOfMed, &yearOfMed);
        if (yearOfMed < givenYear || (yearOfMed == givenYear && monthOfMed < givenMonth)) {
            double oldPrice = medicines[i].price;
            medicines[i].price *= 0.8;
            printf("%s - %s - %.2lf - %.2lf\n", medicines[i].name, medicines[i].date,
                oldPrice, medicines[i].price);
            medicinesChanged++;
        }
    }
    if (medicinesChanged == 0) {
        printf("No medicine with changed price!");
    }
}

/* ===== ЗАДАЧА 3 ===== */
void writeOfferBin(struct Medicine medicines[], int count, int quantity) {
    FILE *file = fopen("offer.bin","wb");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }
    for (int i = 0; i < count; i++) {
        if (medicines[i].quantity > quantity) {
            int nameLen = strlen(medicines[i].name);
            if (fwrite(&nameLen, sizeof(int), 1, file) != 1 ||
                fwrite(medicines[i].name, sizeof(char), nameLen, file) != (size_t)nameLen ||
                fwrite(medicines[i].date, sizeof(char), 8, file) != 8 ||
                fwrite(&medicines[i].code, sizeof(long long), 1, file) != 1 ||
                fwrite(&medicines[i].price, sizeof(double), 1, file) != 1 ||
                fwrite(&medicines[i].quantity, sizeof(int), 1, file) != 1) {
                printf("Error writing to file");
                fclose(file);
                exit(1);
            }
        }
    }
    fclose(file);
}
/* ===== ЗАДАЧА 4 ===== */
void deleteElement(struct Medicine medicines[], int *count, long long code) {
    int deletedElements = 0;
    for (int i = 0; i < *count; i ++) {
        if (medicines[i].code == code) {
            deletedElements++;
            for (int j = i; j < *count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            (*count) --;
            break;
        }
    }
    if (deletedElements == 0) {
        printf("No medicine with deleted elements!");
    }
}

int main() {
    FILE *file = fopen("medicines.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    rewind(file);
    struct Medicine *medicines = (struct Medicine *)malloc(count * sizeof(struct Medicine));
    if (medicines == NULL) {
        printf("Error allocating memory");
        fclose(file);
        exit(1);
    }
    for (int i = 0; i < count; i++) {
        fscanf(file, " %30[^;]; %7[^;]; %lld; %lf; %d\n", medicines[i].name, medicines[i].date,
            &medicines[i].code, &medicines[i].price, &medicines[i].quantity);
    }
    fclose(file);

    /*
      ЗАДАЧА 2
  */
    char giveDate[8];
    printf("Enter date (MM.YYYY): ");
    scanf("%7s", giveDate);
    changePrice(medicines, count, giveDate);

    /*
      ЗАДАЧА 3
  */
    int givenQuantity;
    printf("Enter the quantity: ");
    scanf("%d", &givenQuantity);
    writeOfferBin(medicines, count, givenQuantity);

    /*
     ЗАДАЧА 4
 */
    long long code;
    printf("Enter the code: ");
    scanf("%lld", &code);
    deleteElement(medicines, &count, code);

    free(medicines);
    return 0;
}