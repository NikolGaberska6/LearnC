#include <stdio.h>
int main() {
    int arr[5];
    int i;
    printf("Size of integer in this compiler is %zu\n", sizeof(int));
    //👉 Идеята е: да се покаже колко байта заема int в този компилатор

    for (i = 0; i < 5; i++) {
        printf("Address arr[%d], is %p\n", i, &arr[i]);
         // Address arr[0], is 000000be305ff900
         // Address arr[1], is 000000be305ff904
        // Address arr[2], is 000000be305ff908
       // Address arr[3], is 000000be305ff90c
      // Address arr[4], is 000000be305ff910

    }
}