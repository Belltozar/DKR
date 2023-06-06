#include "Logger.h"

Logger::Logger(const std::string& fileName) {
    logFile.open(fileName, std::ofstream::app);
}

Logger::~Logger() {
    logFile.close();
}

void Logger::log(const std::string& message) {
    logFile << message << std::endl;
}
