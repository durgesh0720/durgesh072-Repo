#include <iostream>
#include <cstring>

const  int MAX_BOOKS = 100;

struct Book {
public:
    char title[100];
    char author[100];
    char ISBN[13];
    bool isAvailable;

    Book(const char* t, const char* a, const char* i) : isAvailable(true) {
        strncpy(title, t, sizeof(title));
        strncpy(author, a, sizeof(author));
        strncpy(ISBN, i, sizeof(ISBN));
    }
};

class Library 
{
public:
    Book books[MAX_BOOKS];
    int bookCount = 0;
    void addBook(const char* title, const char* author, const char* ISBN) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount] = Book(title, author, ISBN);
            bookCount++;
        }
    }

    void displayBooks() {
        for (int i = 0; i < bookCount; i++) {
            std::cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", ISBN: " << books[i].ISBN << ", Available: " << (books[i].isAvailable ? "Yes" : "No") << std::endl;
        }
    }

    void checkOutBook(const char* ISBN) {
        for (int i = 0; i < bookCount; i++) {
            if (strcmp(books[i].ISBN, ISBN) == 0) {
                if (books[i].isAvailable) {
                    books[i].isAvailable = false;
                    std::cout << "Book checked out successfully." << std::endl;
                } else {
                    std::cout << "Book is not available." << std::endl;
                }
                return;
            }
        }
        std::cout << "Book not found." << std::endl;
    }
};

int main() {
    Library library;

    // Adding some sample books
    library.addBook("Book 1", "Author 1", "ISBN-1");
    library.addBook("Book 2", "Author 2", "ISBN-2");

    int choice;
    do {
        std::cout << "Library Management System" << std::endl;
        std::cout << "1. Display Books" << std::endl;
        std::cout << "2. Check Out Book" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                library.displayBooks();
                break;
            case 2:
                char ISBN[13];
                std::cout << "Enter the ISBN of the book you want to check out: ";
                std::cin >> ISBN;
                library.checkOutBook(ISBN);
                break;
            case 3:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}