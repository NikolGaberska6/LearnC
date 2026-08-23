#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patients {
    char ownerName[31];
    char chipNumber[8];
    double price;
};

/* ===== ЗАДАЧА 1: създаване ===== */
struct Patients createPatient() {
    struct Patients p;

    FILE *file = fopen("animalsText.txt", "a");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    printf("Enter the owner name: ");
    fgets(p.ownerName, 31, stdin);
    p.ownerName[strcspn(p.ownerName, "\n")] = '\0';
    printf("Enter the chip number: ");
    fgets(p.chipNumber, 8, stdin);
    p.chipNumber[strcspn(p.chipNumber, "\n")] = '\0';
    printf("Enter the price: ");
    scanf("%lf", &p.price);

    fprintf(file, "%s, %.2lf", p.ownerName, p.price);
    fclose(file);
    return p;
}

void findPatient(struct Patients patient[], int n, double price) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (patient[i].price == price) {
            printf("%s - %s\n", patient[i].ownerName, patient[i].chipNumber);
            found++;
        }
    }
    if (found == 0) {
        printf("Not found!");
    }
}

void readFromBinary(double minPrice) {
    FILE *file = fopen("animalsBin.bin", "rb");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    while (1) {
        int len;
        /* четем дължината на името */
        if (fread(&len, sizeof(int), 1, file) != 1) {
            break;
        }
        struct Patients p;
        /* четем името */
        fread(p.ownerName, sizeof(char), 31, file);
        p.ownerName[len] = '\0';
        /* четем чип номера */
        fread(p.chipNumber, sizeof(char), 8, file);
        /* четем цената */
        fread(&p.price, sizeof(double), 1, file);

        if (p.price >= minPrice) {

            printf("Bin OwnerName: %s\n", p.ownerName);
            printf("Bin ChipNumber: %s\n", p.chipNumber);
            printf("Bin Price: %.2lf\n\n", p.price);
        }
    }
    fclose(file);

}

int main() {
    /*
      ЗАДАЧА 1
  */
    int n;
    printf("Enter the number of patients: ");
    scanf("%d", &n);

    struct Patients patient[n];

    for (int i = 0; i < n; i++) {
       patient[i] =  createPatient();
    }

    /*
      ЗАДАЧА 2
  */
    double price;
    printf("Enter the price: ");
    scanf("%lf", &price);
    findPatient(patient, n, price);

    /*
      ЗАДАЧА 3
  */
    double minPrice;
    printf("Enter the price: ");
    scanf("%lf", &minPrice);
    readFromBinary(minPrice);

    return 0;
}