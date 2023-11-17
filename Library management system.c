#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[100];
    char author[100];
    int year;
    int pages;
} Book;

Book* library[100];
int num_books = 0;

void add_book()
{
    char title[100];
    char author[100];
    int year;
    int pages;
    printf("Enter the title of the book: ");
    scanf("%s", title);
    printf("Enter the name of the author: ");
    scanf("%s", author);
    printf("Enter the year of publication: ");
    scanf("%d", &year);
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    Book* new_book = (Book*) malloc(sizeof(Book));
    strcpy(new_book->title, title);

    strcpy(new_book->author, author);
    new_book->year = year;
    new_book->pages = pages;
    library[num_books] = new_book;
    num_books++;
    printf("Book added successfully!\n\n\n");
}

void edit_book()
{
    char title[100];
    printf("Enter the title of the book to edit: ");
    scanf("%s", title);
    for (int i = 0; i < num_books; i++)
    {
        if (strcmp(library[i]->title, title) == 0)
        {
            printf("Enter the new title of the book: ");
            scanf("%s", library[i]->title);
            printf("Enter the new name of the author: ");
            scanf("%s", library[i]->author);
            printf("Enter the new year of publication: ");
            scanf("%d", &library[i]->year);
            printf("Enter the new number of pages: ");
            scanf("%d", &library[i]->pages);
            printf("Book edited successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

void delete_book()
{
    char title[100];
    printf("Enter the title of the book to delete: ");
    scanf("%s", title);
    for (int i = 0; i < num_books; i++)
    {
        if (strcmp(library[i]->title, title) == 0)
        {
            free(library[i]);
            for (int j = i; j < num_books - 1; j++)
            {
                library[j] = library[j+1];
            }
            num_books--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. Add book\n");
        printf("2. Edit book\n");
        printf("3. Delete book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            add_book();
            break;
        case 2:
            edit_book();
            break;
        case 3:
            delete_book();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
