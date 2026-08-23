#include <stdio.h>

int main() {
    char text[100];
    char first[100];
    int i = 0;

    printf("Enter a sentence: ");
    fgets(text, sizeof(text), stdin);

    // копира първата дума
    while (text[i] != ' ' && text[i] != '\0' && text[i] != '\n') {
        first[i] = text[i];
        i++;
    }

    // завършваме низа правилно
    first[i] = '\0';

    printf("First word: %s\n", first);

    return 0;
}