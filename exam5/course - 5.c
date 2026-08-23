#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Course {
    long long courseNumber;
    char courseName[129];
    char teacherName[65];
    char startDate[11];
    int enrolledStudents;
};

struct Student {
    char studentName[65];
    long long facultyNumber;
    int numCourse;
    long long* courseNumbers;
};

/* ===== ЗАДАЧА 2: филтриране ===== */
int compareDates (struct Course courses[], int count, char name[], char startDate[], char endDate[]) {
    FILE *file = fopen("course_info.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    int d1, m1, y1;
    int d2, m2, y2;
    // начална дата
    sscanf(startDate, "%d.%d.%d", &d1, &m1, &y1);
    // крайна дата
    sscanf(endDate, "%d.%d.%d", &d2, &m2, &y2);

    int courseCount = 0;

    for (int i = 0; i < count; i++) {
        int d, m, y;
        // дата на курса
        sscanf(courses[i].startDate, "%d.%d.%d", &d, &m, &y);

        //"още НЕ знаем дали датата е след началната"
        int afterStart = 0;
        //"още НЕ знаем дали датата е преди крайната"
        int beforeEnd= 0;

        // проверка за дата
        if (strcmp(courses[i].teacherName, name) == 0 &&
            (y > y1 ||
            (y == y1 && m > m1) ||
            (y == y1 && m == m1 && d >= d1))
            && (y < y2 ||
            (y == y2 && m < m2) ||
            (y == y2 && m == m2 && d <= d2))) {
            fprintf(file, "%lld :%s :%s -%d\n",
                courses[i].courseNumber, courses[i].courseName,
                courses[i].startDate, courses[i].enrolledStudents);
            courseCount++;
            }
    }
    fclose(file);
    return courseCount;
}

/* ===== ЗАДАЧА 3: филтриране ===== */
int enrolledStudents(struct Course courses[], int nCourse,
    struct Student students[], int mStudent,
    long long facultyNumber, long long courseNumber){
    FILE *file = fopen("course_student.bin", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    


}

int main() {
    int nCourse, mStudents;

    printf("Enter the number of courses: ");
    scanf("%d", &nCourse);

    struct Course *courses = (struct Course *)malloc(nCourse * sizeof(struct Course));
    if (courses == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    for (int i = 0; i < nCourse; i++) {
        scanf("%lld", &courses[i].courseNumber);
        scanf("%s", courses[i].courseName);
        scanf("%s", courses[i].teacherName);
        scanf("%s", courses[i].startDate);
        courses[i].enrolledStudents = 0;
    }

    printf("Enter the number of students: ");
    scanf("%d", &mStudents);
    struct Student* students = (struct Student*)malloc(mStudents * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    for (int i = 0; i < mStudents; i++) {
        scanf("%s", students[i].studentName);
        scanf("%lld", &students[i].facultyNumber);
        scanf("%d", &students[i].numCourse);

        students[i].courseNumbers = (long long *)malloc(students[i].numCourse * (sizeof(long long)));
        for (int j = 0; j < students[i].numCourse; j++) {
            scanf("%lld", &students[i].courseNumbers[j]);
        }
    }
    for (int i = 0; i < mStudents; i++) {
        free(students[i].courseNumbers);
    }
    free(students);

    /*
    ЗАДАЧА 2 – филтриране
    */
    char name[65];
    char startDate[11];
    char endDate[11];
    printf("Teacher: ");
    scanf("%s", name);
    printf("Start date: ");
    scanf("%s", startDate);
    printf("End date: ");
    scanf("%s", endDate);
    printf("Result is: %d", compareDates(courses, nCourse, name, startDate, endDate));

    free(courses);
    return 0;
}