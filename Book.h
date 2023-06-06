#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
public:
    // ������������
    Book();
    Book(int id, const std::string& title, const std::string& author, const std::string& publisher,
         int year, int numPages, double price, const std::string& bindingType);

    // �������
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getPublisher() const;
    int getYear() const;
    int getNumPages() const;
    double getPrice() const;
    std::string getBindingType() const;

    // �������
    void setId(int id);
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setPublisher(const std::string& publisher);
    void setYear(int year);
    void setNumPages(int numPages);
    void setPrice(double price);
    void setBindingType(const std::string& bindingType);

    // ���������� ��������� ������ ��� �����
    friend std::ostream& operator<<(std::ostream& os, const Book& book);

    // ������������ ��'���� ����� � �����
    std::string toString() const;

private:
    int id;
    std::string title;
    std::string author;
    std::string publisher;
    int year;
    int numPages;
    double price;
    std::string bindingType;
};

#endif  // BOOK_H
