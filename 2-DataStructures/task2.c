#include <stdio.h>
#include <string.h>

int id_counter = 0;

struct Books {
    char title[64];
    char author[64];
    char subject[64];
    int id;
} book;


struct Books makeBook(char title[64], char author[64], char subject[64]) {
    struct Books Book;
    strcpy(Book.title, title);
    strcpy(Book.author, author);
    strcpy(Book.subject, subject);
    Book.id = ++id_counter;
    return Book;
}

void printBook(struct Books Book) {
    printf("Book %d info:\n\t"
    "Title: %s\n\t"
    "Author: %s\n\t"
    "Subject: %s\n", 
    Book.id, Book.title, Book.author, Book.subject);
}

int main()
{
    struct Books book1 = makeBook("C Learning", "Ben Cox", "Programming");
    struct Books book2 = makeBook("C Teaching", "Liam Wilson-Storey", "Programming");
    struct Books book3 = makeBook("C Teaching (but more)", "Ryan Impey", "Programming");

    struct Books library[3] = {book1, book2, book3};
    printf("sizeof library = %lu\n\n", sizeof(library));

    for (int i = 0; i < sizeof(library)/sizeof(library[0]); i++) // Would like to clarify this length of array method.
    {
        printBook(library[i]);
    }
    
    return 0;

}