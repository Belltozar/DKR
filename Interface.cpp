#include "Interface.h"
#include <limits>
Interface::Interface(std::vector<Book>& books, Logger& logger)
    : books(books), logger(logger) {}

void Interface::listBooksByAuthor() const {
    std::string author;
    std::cout << "Enter the author name: ";
    std::getline(std::cin, author);

    std::cout << "Books by author " << author << ":" << std::endl;
    for (const Book& book : books) {
        if (book.getAuthor() == author) {
            std::cout << book << std::endl;
        }
    }

    logger.log("Listed books by author: " + author);
}

void Interface::listBooksByPublisher() const {
    std::string publisher;
    std::cout << "Enter the publisher name: ";
    std::getline(std::cin, publisher);

    std::cout << "Books by publisher " << publisher << ":" << std::endl;
    for (const Book& book : books) {
        if (book.getPublisher() == publisher) {
            std::cout << book << std::endl;
        }
    }

    logger.log("Listed books by publisher: " + publisher);
}

void Interface::listBooksPublishedAfterYear() const {
    int year;
    std::cout << "Enter the year: ";
    std::cin >> year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Books published after " << year << ":" << std::endl;
    for (const Book& book : books) {
        if (book.getYear() > year) {
            std::cout << book << std::endl;
        }
    }

    logger.log("Listed books published after year: " + std::to_string(year));
}
