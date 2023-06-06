#include "Book.h"

// Default constructor
Book::Book() {
    id = 0;
    year = 0;
    numPages = 0;
    price = 0.0;
}

// Parameterized constructor
Book::Book(int id, const std::string& title, const std::string& author, const std::string& publisher,
           int year, int numPages, double price, const std::string& bindingType)
    : id(id), title(title), author(author), publisher(publisher), year(year),
      numPages(numPages), price(price), bindingType(bindingType) {
}

// Getter methods
int Book::getId() const {
    return id;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getPublisher() const {
    return publisher;
}

int Book::getYear() const {
    return year;
}

int Book::getNumPages() const {
    return numPages;
}

double Book::getPrice() const {
    return price;
}

std::string Book::getBindingType() const {
    return bindingType;
}

// Setter methods
void Book::setId(int id) {
    this->id = id;
}

void Book::setTitle(const std::string& title) {
    this->title = title;
}

void Book::setAuthor(const std::string& author) {
    this->author = author;
}

void Book::setPublisher(const std::string& publisher) {
    this->publisher = publisher;
}

void Book::setYear(int year) {
    this->year = year;
}

void Book::setNumPages(int numPages) {
    this->numPages = numPages;
}

void Book::setPrice(double price) {
    this->price = price;
}

void Book::setBindingType(const std::string& bindingType) {
    this->bindingType = bindingType;
}

// Output to console
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "ID: " << book.id << std::endl;
    os << "Title: " << book.title << std::endl;
    os << "Author: " << book.author << std::endl;
    os << "Publisher: " << book.publisher << std::endl;
    os << "Year of Publication: " << book.year << std::endl;
    os << "Number of Pages: " << book.numPages << std::endl;
    os << "Price: " << book.price << std::endl;
    os << "Binding Type: " << book.bindingType << std::endl;
    return os;
}

std::string Book::toString() const {
    std::string data;
    data += std::to_string(id) + ";";
    data += title + ";";
    data += author + ";";
    data += publisher + ";";
    data += std::to_string(year) + ";";
    data += std::to_string(numPages) + ";";
    data += std::to_string(price) + ";";
    data += bindingType;
    return data;
}
