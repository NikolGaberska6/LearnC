#include <stdio.h>
int main () {
    char text[100];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    int countWords = 0;
    int i = 0;
    while (text[i] != '\0') {
        // ако текущият символ е буква И предишният е интервал или начало
        if (text[i] != ' ' && (text[i - 1] == ' ' || i == 0)) {
            countWords++;
        }
        i++;
    }

    printf("Count of words in sentence is: %d", countWords);

}