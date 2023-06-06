#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <limits>
#include "Book.h"
#include "Logger.h"

class Interface {
public:
    // �����������
    Interface(std::vector<Book>& books, Logger& logger);

    // ������� ������ ���� �� �������
    void listBooksByAuthor() const;

    // ������� ������ ���� �������� ������������
    void listBooksByPublisher() const;

    // ������� ������ ���� ������� ���� ������� ����
    void listBooksPublishedAfterYear() const;

private:
    std::vector<Book>& books;
    Logger& logger;
};

#endif  // INTERFACE_H
