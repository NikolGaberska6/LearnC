#include <stdio.h>
#include <string.h>

struct Books {
    char title[50];
    char author[50];
    char subject[50];
    int book_id;
};

void printBook(struct Books *book) {
    printf("Book title: %s\n", book->title);
    printf("Book author: %s\n", book->author);
    printf("Book subject: %s\n", book->subject);
    printf("Book book_id: %d\n", book->book_id);
    //достъп до поле от указателя:
    //struct_pointer->title;
}

int main() {
    struct Books Book1;
    struct Books Book2;

    /* book 1 specification */
    strcpy(Book1.title, "C Programming");
    strcpy(Book1.author, "Marija Programming");
    strcpy(Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

    /* book 2 specification */
    strcpy(Book2.title, "BPE materials");
    strcpy(Book2.author,"Haralampi Spiridonov");
    strcpy(Book2.subject, "Materials for BPE subject");
    Book2.book_id = 6495700;

    printBook(&Book1);
    printBook(&Book2);

    return 0;

}