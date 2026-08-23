#include <stdio.h>
#include <string.h>

struct Books {
    char title[50];
    char author[50];
    char subject[50];
    int book_id;
};

int main() {
    struct Books Book1;
    struct Books Book2;
    //създаваш две отделни променливи от тип структура
    //✔️ казва „имаме 2 отделни обекта (променливи) от тип Books

    /* book 1 specification */
    strcpy(Book1.title, "C Programming");
    strcpy(Book1.author, "Marija Programming");
    strcpy(Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;
    //Този код използва strcpy, за да запише
    //текст (низове) в полетата на структурата Book1.

    /* book 2 specification */
    strcpy(Book2.title, "BPE materials");
    strcpy(Book2.author,"Haralampi Spiridonov");
    strcpy(Book2.subject, "Materials for BPE subject");
    Book2.book_id = 6495700;

    /* print Book1 info */
    printf("Book1 title: %s\n", Book1.title);
    printf("Book1 author: %s\n", Book1.author);
    printf("Book1 subject: %s\n", Book1.subject);
    printf("Book1 book_id: %d\n", Book1.book_id);

    /* print Book1 info */
    printf( "Book 2 title : %s\n", Book2.title);
    printf( "Book 2 author : %s\n", Book2.author);
    printf( "Book 2 subject : %s\n", Book2.subject);
    printf( "Book 2 book_id : %d\n", Book2.book_id);

    return 0;

}