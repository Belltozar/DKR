#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <limits>
#include "Book.h"
#include "Logger.h"

class Interface {
public:
    // Конструктор
    Interface(std::vector<Book>& books, Logger& logger);

    // Вивести список книг за автором
    void listBooksByAuthor() const;

    // Вивести список книг виданого видавництвом
    void listBooksByPublisher() const;

    // Вивести список книг виданих після певного року
    void listBooksPublishedAfterYear() const;

private:
    std::vector<Book>& books;
    Logger& logger;
};

#endif  // INTERFACE_H
