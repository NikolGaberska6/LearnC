#include <stdio.h>

void suma(int *a, int *b, int *result) {
    //👉 Функцията приема адрес (указател)
    *result = *a + *b;
    //👉 Вътре използваме *, за да „отворим“ адреса и да работим със стойността
    //👉 новата стойност се записва на адреса, който result сочи
}

void razlika(int *a, int *b, int *result) {
    *result = *a - *b;
    //👉 новата стойност се записва на адреса, който result сочи
}

void umnojenie(int *a, int *b, int *result) {
    *result = *a * *b;
    //👉 новата стойност се записва на адреса, който result сочи
}

void delenie (int *a, int *b, float *result) {
    if (*b != 0) {
        *result = (float)(*a) / (*b);
        //👉 новата стойност се записва на адреса, който result сочи
    } else {
        printf("Error dividing by zero!");
    }
}

int main() {
    int a, b;
    int sum, diff, multiply;
    float div;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    suma(&a, &b, &sum);
    //💡 Лесно обяснение:
    //Представи си:
    //x = 5 е кутия със стойност 5
    //&x е адресът на кутията
    //*a е „отвори кутията и вземи стойността“

    razlika(&a, &b, &diff);
    umnojenie(&a, &b, &multiply);
    delenie(&a, &b, &div);

    printf("Sum is: %d\n", sum);
    printf("Difference is: %d\n", diff);
    printf("Multiply is: %d\n", multiply);
    printf("Division is: %lf\n", div);

    return 0;
}