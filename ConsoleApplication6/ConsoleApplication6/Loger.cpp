#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>


class Logger {
public:
    static void log(const std::string& message) {
        std::ofstream logFile("logger.txt", std::ios_base::app);
        logFile << message << std::endl;
    }
};