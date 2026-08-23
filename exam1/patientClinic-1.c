#include <stdio.h>
#include <string.h>

// Дефиниция на структура
struct Patient { //това е тип данни (като int, float, char).
    char ownerName[31];
    char chipNumber[8]; // "A12345B" + '\0'
    float price;
};

// ===== ЗАДАЧА 1 =====
// Функция без параметри
struct Patient createPatient() {
    struct Patient p;
    //👉 ти реално създаваш: една „кутия“ в паметта която съдържа:
    //име //чип номер //цена

    // Въвеждане на данни

    printf("Enter owner name: ");
    //Чете цял ред текст от клавиатурата и го записва в p.ownerName
    fgets(p.ownerName, 31, stdin);
    //премахва новия ред (\n), който fgets() често оставя в края на текст
    p.ownerName[strcspn(p.ownerName, "\n")] = '\0';

    printf("Enter the chip number (format A12345B): ");
    fgets(p.chipNumber, 8, stdin);
    // махаме новия ред от fgets
    p.chipNumber[strcspn(p.chipNumber, "\n")] = '\0';

    printf("Enter the price: ");
    scanf("%f", &p.price);

    //изчистване на буфера
    getchar(); // чистим '\n'

    // Запис във файл
    FILE *file = fopen("animalsText.txt", "a");

    if (file == NULL) {
        printf("Error with open the file!\n");
        return p; //Прекрати функцията веднага и върни текущия пациент p
    }

    fprintf(file, "%s, %.2f\n", p.ownerName, p.price);
    //Това е ред, който записва информация във файл.

    fclose(file);
    return p;
    //записваш във файла
    //затваряш файла
    //връщаш структурата
}

// ===== ЗАДАЧА 2 =====
// функция за търсене
void printPatient(struct Patient patients[], int n, float price) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (patients[i].price == price) {
            printf("%s - %s", patients[i].ownerName, patients[i].chipNumber);
            found = 1;
        }
    }
    if (!found) {
        printf("No patient found!\n");
    }
}

// ===== ЗАДАЧА 3 =====
// функция за цена
void printFromBinary(float price) {
    FILE *file = fopen("animalBin.bin.txt", "rb");
    if (file == NULL) {
        printf("Error with open the file!\n");
        return;
    }

    struct Patient p;
    int nameLen;

    while (fread(&nameLen, sizeof(int), 1, file) == 1) {
        //редът във файла е: [дължина][име][чип][цена]

        //1. Четене на името
        fread(p.ownerName, sizeof(char), nameLen, file);
        p.ownerName[nameLen] = '\0';

        //2. Четене на чип номер
        fread(p.chipNumber, sizeof(char), 8, file);
        //Чипът е с фиксирана дължина (например "A12345B")
        //👉 и обикновено:
        //или вече съдържа '\0'

        //3.Четене на цена
        fread(&p.price, sizeof(float), 1, file);

        if (p.price >= price) {
            printf("Bin OwnerName: %s\n", p.ownerName);
            printf("Bin Cip: %s\n", p.chipNumber);
            printf("Bin Price: %.2f\n", p.price);
        }
    }

    fclose(file);
}


int main() {

    //задача 1
    struct Patient patients[100]; //"Направи масив от елементи от тип struct Patient"

    int count = 0;
    char choice = 'y';

    while (choice == 'y') {
        patients[count] = createPatient();
        //Създава нов пациент и го записва в масива.
        count++;

        printf("Do you want to add more patients (y/n): ");
        scanf(" %c", &choice);
        getchar();
    }

    //задача 2
    float price;
    printf("Enter the search price: ");
    scanf("%f", &price);
    printPatient(patients, count, price);

    //задача 3
    float searchedPrice;
    printf("Enter the search price: ");
    scanf("%f", &searchedPrice);
    printFromBinary(searchedPrice);

    return 0;
}