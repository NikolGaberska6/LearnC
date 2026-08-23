#include <stdio.h>
int main () {
    int num[3][4] = {
        {1, 2,  3,  4},
        {5, 6,  7,  8},
        {9, 10, 11, 12}
    };
    int *ptr = &num[0][0];
    //👉 това е: адресът на първия елемент на матрицата
    //т.е. адреса на числото 1

    int rows = 3;
    int cols = 4;
    int totalCells = rows * cols;
    int i;
    for (i = 0; i < totalCells; i++) {
        printf("%d ", *(ptr + i));
        //👉 ptr + i ---> мести се напред в паметта
        //👉*(ptr + i) ---> взима стойността на този адрес
    }
    return 0;

}
