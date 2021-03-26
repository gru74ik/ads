#include "Logger.h"

int main()
{
    for ([[maybe_unused]] const auto& elem : {1, 2, 3, 4, 5})
    {
        Logger::instance().log("logged message: " + std::to_string(elem));
    }
}