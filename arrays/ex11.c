#include <ctype.h>
#include <stdio.h>
int main() {
    char text[100];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    int i = 0;

    while (text[i] != '\0') {
        text[i] = toupper(text[i]);
        i++;
    }

    printf("The text is: %s", text);
}