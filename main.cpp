#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <bitset> // for XOR encryption
#include "Book.h"
#include "Logger.h"
#include "Interface.h"

void writeEncryptedFile(const std::vector<Book>& books, const std::string& fileName) {
    std::ofstream file(fileName, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    // XOR encryption key
    std::bitset<8> encryptionKey(0b01010101);

    for (const Book& book : books) {
        std::string encryptedData = book.toString();

        // XOR encryption
        for (char& c : encryptedData) {
            c ^= encryptionKey.to_ulong();
        }

        file.write(encryptedData.c_str(), encryptedData.size());
        file.put('\n');
    }

    file.close();

    std::cout << "Encrypted file written successfully." << std::endl;
}

void addBook(std::vector<Book>& books) {
    int id, year, numPages;
    std::string title, author, publisher, bindingType;
    double price;

    std::cout << "Enter book details:" << std::endl;
    std::cout << "ID: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Title: ";
    std::getline(std::cin, title);

    std::cout << "Author: ";
    std::getline(std::cin, author);

    std::cout << "Publisher: ";
    std::getline(std::cin, publisher);

    std::cout << "Year of Publication: ";
    std::cin >> year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Number of Pages: ";
    std::cin >> numPages;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Price: ";
    std::cin >> price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Binding Type: ";
    std::getline(std::cin, bindingType);

    Book book(id, title, author, publisher, year, numPages, price, bindingType);
    books.push_back(book);

    std::cout << "Book added successfully." << std::endl;
}

void removeBook(std::vector<Book>& books) {
    int id;
    std::cout << "Enter the ID of the book to remove: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto it = std::find_if(books.begin(), books.end(), [id](const Book& book) {
        return book.getId() == id;
    });

    if (it != books.end()) {
        books.erase(it);
        std::cout << "Book with ID " << id << " removed successfully." << std::endl;
    } else {
        std::cout << "Book with ID " << id << " not found." << std::endl;
    }
}

void printMenu() {
    std::cout << "=== Book Management System ===" << std::endl;
    std::cout << "1. Add Book" << std::endl;
    std::cout << "2. Remove Book" << std::endl;
    std::cout << "3. List Books by Author" << std::endl;
    std::cout << "4. List Books by Publisher" << std::endl;
    std::cout << "5. List Books Published After a Year" << std::endl;
    std::cout << "6. Save Encrypted Data to a File" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    Logger logger("log.txt");
    std::vector<Book> books;

    // Creating initial books
    books.emplace_back(1, "Book 1", "Author 1", "The Sum 41 ", 2020, 250, 19.99, "Hardcover");
    books.emplace_back(2, "Book 2", "Author 2", "Pain", 2018, 300, 24.99, "Paperback");
    books.emplace_back(3, "Book 3", "Author 1", "Nine inch nails", 2022, 400, 29.99, "Hardcover");

    Interface interface(books, logger);

    int choice;
    do {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                removeBook(books);
                break;
            case 3:
                interface.listBooksByAuthor();
                break;
            case 4:
                interface.listBooksByPublisher();
                break;
            case 5:
                interface.listBooksPublishedAfterYear();
                break;
            case 6: {
                std::string fileName;
                std::cout << "Enter the file name to save encrypted data: ";
                std::getline(std::cin, fileName);

                writeEncryptedFile(books, fileName);
                break;
            }
            case 7:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (choice != 7);

    return 0;
}
