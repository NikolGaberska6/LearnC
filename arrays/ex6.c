#include <stdio.h>
int main () {
    char text[100];
    printf("Enter a string: ");
    fgets(text, 100, stdin);

    printf("The string you entered is: %s", text);
}