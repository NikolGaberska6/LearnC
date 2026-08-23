#include <stdio.h>
#include <stdlib.h>

struct Course {
    char courseName[51];
    char startDate[11];
    int lectures;
    double price;
};

// ===== ЗАДАЧА 1 =====
// функция за намаление
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

int main() {
    FILE *file = fopen("course.bin", "rb");
    if (file == NULL) {
        printf("Course file could not be opened\n");
        return 1;
    }
    int n;

    //запазваме данните за актуалния
    //брой курсове запазете в целочислена променлива n.
    if (fread((&n), sizeof(int), 1, file) != 1) {
        //успях ли да прочета броя курсове (n) от файла?
        //fread(...) ---> „прочети нещо от файла“
        //&n ---> „запиши прочетеното число в n“
        //1 ---> „прочети 1 число“
        //file ---> "от кой файл да чете"
        // != 1 ---> „ако не е прочетено точно 1 число → има проблем“
        //👉 Проверяваме дали успешно е прочетено точно едно число от
        //файла (в твоя случай n), и ако това е така, значи можем спокойно
        //да продължим, защото файлът започва правилно и данните са валидни
        //за следващите стъпки.
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

    if (fread(courses, sizeof(struct Course), n, file) != n) {
        //Успях ли да прочета всички курсове от файла?
        //fread(...) ---> връща колко елемента е прочела успешно
        printf("Error reading file\n");
        free(courses);
        fclose(file);
        return 1;
    }

    fclose(file);
    
    int index;
    printf("Enter the index of the course: ");
    scanf("%d", &index);
    applyDiscount(courses, n, index);

    free(courses);

    return 0;
}