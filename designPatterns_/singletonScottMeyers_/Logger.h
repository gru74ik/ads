#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

class Logger //Logger implemented as Scott Meyers' singleton
{
public:
    static Logger & instance()
    {
        static Logger logger;
        return logger;
    }

    void log(const std::string & message)
    {
        std::cout << message << std::endl;
    }

    Logger(const Logger & notCopyable) = delete;
    Logger & operator=(const Logger & notAssignable) = delete;
    Logger(Logger && notMoveable) = delete;
    Logger & operator=(Logger && notMoveAssignable) = delete;

private:
    Logger() = default;
    ~Logger() = default;
};

#endif //LOGGER_H