#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Course {
    char courseName[51];
    char startDate[11];
    int lectures;
    double price;
};

/* ===== ЗАДАЧА 2: намаление ===== */
void applyDiscount(struct Course courses[], int number, int index) {
    //проверка за валиден индекс
    if (index < 0 || index >= number) {
        printf("Invalid index!");
        return;
    }
    courses[index].price *= 0.9;

    printf("%.2lf lv - %s - %s", courses[index].price,
        courses[index].courseName, courses[index].startDate);
}

/* ===== ЗАДАЧА 3: запис в текстов файл ===== */
int writeOffers(struct Course courses[], int number, double min, double max) {
    FILE *file = fopen("offers.txt", "w");
    if (file == NULL) {
        printf("Error opening file");
        return 0;
    }

    int count = 0;
    for (int i = 0; i < number; i++) {
        if (courses[i].price >= min && courses[i].price <= max) {
            fprintf(file, "%s\n %s\n %d lectures\n, %.2f\n",
                courses[i].courseName, courses[i].startDate,
                courses[i].lectures, courses[i].price); //записваме във файла
            count++;
        }
    }
    fclose(file);
    return count;
}

/* ===== ЗАДАЧА 4: изтриване ===== */
struct Course* deleteCourse(struct Course *courses, int n, char name[], char date[]) {
    if (courses == NULL || n <= 0) {
        return NULL;
    }

    int index = -1;
    //-1 НЕ може да е индекс в масив
    //„нищо не е намерено“

    for (int i = 0; i < n; i++) {
        if (strcmp(courses[i].courseName, name) == 0
            && strcmp(courses[i].startDate, date) == 0) {
            //сравнява два низа дали са еднакви
            index = i;
            break;
        }
    }

    if (index == -1) {
        return courses;
    }

    // местене наляво
    for (int i = index; i < n - 1; i++) {
        courses[i] = courses[i + 1];
    }

    // свиване на масива
    struct Course *temp = (struct Course *)realloc(courses, (n-1) * sizeof(struct Course));

    // проверка
    if (temp == NULL && n-1 > 0) {
        return NULL;
    }

    return temp;
}


int main() {

    /* ===== ЗАДАЧА 1 ===== */
    FILE *file = fopen("courses.bin", "rb");
    if (file == NULL) {
        printf("Course file could not be opened\n");
        return 1;
    }
    int n;

    //запазваме данните за актуалния
    //брой курсове запазете в целочислена променлива n.
    if (fread((&n), sizeof(int), 1, file) != 1) {
       // ако не успееш да прочетеш n, не знаеш колко данни има
        printf("Error reading file\n");
        fclose(file);
        return 1;
    }

    // динамичен масив
    //заделяме данните от файла в динамичен масив courses с елементи от тип структурата Course
    struct Course *courses = (struct Course*)malloc(n * sizeof(struct Course));
    if (courses == NULL) {
        printf("Error allocating courses\n");
        fclose(file);
        return 1;
    }

    if (fread(courses, sizeof(struct Course), n, file) != (size_t)n) {
        //Успях ли да прочета всички курсове от файла?
        printf("Error reading file\n");
        free(courses);
        fclose(file);
        return 1;
    }

    fclose(file);

    /* ===== ЗАДАЧА 2 ===== */
    int idx;
    printf("Enter the index of the course: ");
    scanf("%d", &idx);
    applyDiscount(courses, n, idx);

    /* ===== ЗАДАЧА 3 ===== */
    double min, max;
    printf("Enter the min and max price: ");
    scanf("%lf %lf", &min, &max);

    int result = writeOffers(courses, n, min, max);
    printf("Written offers are: %d", result);

    /* ===== ЗАДАЧА 4 ===== */
    char name[51];
    char date[11];

    printf("Enter the course name: ");
    scanf(" %s", name);
    printf("Enter the starting date: ");
    scanf("%s", date);

    courses = deleteCourse(courses, n, name, date);
    n--;

    free(courses);

    return 0;
}