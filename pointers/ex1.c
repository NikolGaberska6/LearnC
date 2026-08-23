#include <stdio.h>

void birthday(int* age) {
    age++;
}

int main() {
    int age = 25;
    printf("%p\n", &age); //0000005ebc5ffa84

    int *pAge = &age; //pointer to age
    printf("%p", pAge);
    //*pAge = 0000005ebc5ffa84

    birthday(pAge);
    printf("You are %d years old", age);

    return 0;
}