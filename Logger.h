#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

class Logger {
public:
    // Конструктор
    explicit Logger(const std::string& fileName);

    // Деструктор
    ~Logger();

    // Запис повідомлення до файлу
    void log(const std::string& message);

private:
    std::ofstream logFile;
};

#endif  // LOGGER_H
