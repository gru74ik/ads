#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include "Singleton.h"

class Logger : public Singleton<Logger>
{
public:
    void log(const std::string& message)
    {
        std::cout << message << std::endl;
    }
};

#endif //LOGGER_H