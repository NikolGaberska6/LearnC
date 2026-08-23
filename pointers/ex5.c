#include <stdio.h>
int main() {
    int a = 10;  // обикновена променлива
    int *p;     // декларация на указател
    p = &a;    // присвояване на адреса на a към указателя

    printf("The value of a is: %d\n", a);
    printf("The address of a is: %p\n", &a);

    printf("The address of pointer: %p\n", p);
    printf("The value of pointer: %d\n", *p);

    return 0;

}