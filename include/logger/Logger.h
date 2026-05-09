#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

class Logger {
private:
    std::ofstream logFile;

public:
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::out);
    }

    ~Logger() {
        if (logFile.is_open()) logFile.close();
    }

    void log(const std::string& message) {
        if (logFile.is_open()) {
            logFile << "[LOG] " << message << std::endl;
        }
        std::cout << "[LOG] " << message << std::endl;
    }
};

extern Logger globalLogger;

#endif
