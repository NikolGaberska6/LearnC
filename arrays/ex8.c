#include <stdio.h>
int main() {
    char text[100];
    int i = 0;
    int count = 0;

    printf("Enter a string: ");
    fgets(text, 100, stdin);

    while (text[i] != '\0') {
        count++;
        i++;
    }

    printf("The length of the string is: %d", count);
    return 0;

}