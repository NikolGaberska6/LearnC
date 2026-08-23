#include <stdio.h>
int main() {
    int number; //3
    printf("Enter a number:");
    scanf("%d", &number);
     for (int i = 1; i <= number; i++) { //редовете - в случая 3
         for (int j = 1; j <= i; j++) {  //колко пъти да се печата числото
             printf("%d ", i);
         }
        printf("\n"); // нов ред
     }
 }

// int main() {
//     int number;
//     printf("Enter a number: ");
//     scanf("%d", &number);
//
//     for (int i = 1; i <= number; i++) { //3 puti kato ---> i = 1; i = 2....
//         for (int j = 1; j <= i; j++) {
//             printf("%d", i);
//         }
//         printf("\n");
//
//     }
// }