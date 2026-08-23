#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Treatment {
    int identicalNum;
    char date[11];
    char name[31];
    char diagnoza[51];
};

/* ===== ЗАДАЧА 2 ===== */
int count_treatment(struct Treatment history[], int n, char name[], char diagnoza[]) {
    int countPatient = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(history[i].name, name) == 0 &&
            strcmp(history[i].diagnoza, diagnoza) == 0) {
            countPatient++;
        }
    }
    return countPatient;
}

/* ===== ЗАДАЧА 3 ===== */
struct Treatment *add_new_treatment(struct Treatment *history, int *n) {
    struct Treatment new_treatment;

    printf("Enter id: ");
    scanf("%d", &new_treatment.identicalNum);
    printf("Enter date (DD.MM.YYYY): ");
    scanf("%10s", new_treatment.date);
    printf("Enter name: ");
    scanf("%30s", new_treatment.name);
    printf("Enter diagnoza: ");
    scanf("%50s", new_treatment.diagnoza);

    struct Treatment *temp =
        realloc(history, (*n + 1) * sizeof(struct Treatment));

    if (temp == NULL)
    {
        printf("Memory allocation error!");
        return NULL;
    }
    history = temp;

    history[*n] = new_treatment;
    (*n)++;
    return history;
}

/* ===== ЗАДАЧА 4 ===== */
int write_text_file(struct Treatment history[], int count, char diagnoza[]) {
    FILE *file = fopen("illness.txt", "w");
    if (file == NULL) {
        printf("Error opening file!");
        return 0;
    }
    int counter = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(history[i].diagnoza, diagnoza) == 0) {
            fprintf(file, "Bolnichni prestoy na pacient %s\n", history[i].name);
            fprintf(file,"Za lechenie na: %s\n\n", history[i].diagnoza);
            fprintf(file, "Data: %s\n", history[i].date);
            counter++;
        }
    }
    fclose(file);
    return counter;
}


int main() {
    FILE *file = fopen("history.bin", "rb");
    if (file == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    int n;

    if (fread(&n, sizeof (int), 1, file) != 1) {
        printf("Error reading file!");
        fclose(file);
        exit(1);
    }

    struct Treatment *history = (struct Treatment*)malloc(n * sizeof(struct Treatment));
    if (history == NULL) {
        printf("Error allocating memory!");
        exit(1);
    }

    if (fread(history, sizeof (struct Treatment), n, file) != n) {
        printf("Error reading file!");
        free(history);
        fclose(file);
        exit(1);
    }

    fclose(file);
}