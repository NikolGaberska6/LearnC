#include <stdio.h>

int main() {
    char text[100];
    int freq[26] = {0};  // за a-z
//     0 -> a
//     1 -> b
//     2 -> c
//     ...
//     25 -> z

    int i = 0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    while (text[i] != '\0') {

        // малки букви
        if (text[i] >= 'a' && text[i] <= 'z') {
            freq[text[i] - 'a']++;
            //'c' - 'a' = 2 ---> дава индекса на буквата
            //увеличава броя на буквата 'c'
            //буква - 'a' = позиция в азбуката
        }

        // главни букви
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            freq[text[i] - 'A']++;
            //'C' - 'A' = 2 ---> дава индекса на буквата
        }

        i++;
    }

    printf("\nLetter frequencies:\n");

    for (i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c -> %d\n", i + 'a', freq[i]);
        }
    }

    return 0;
}