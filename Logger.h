#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

class Logger {
public:
    // �����������
    explicit Logger(const std::string& fileName);

    // ����������
    ~Logger();

    // ����� ����������� �� �����
    void log(const std::string& message);

private:
    std::ofstream logFile;
};

#endif  // LOGGER_H
