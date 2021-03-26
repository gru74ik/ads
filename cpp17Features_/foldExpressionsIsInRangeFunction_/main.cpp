#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T, typename ... Ts>
bool within(T min, T max, Ts ...ts)
{   // The expression (min <= ts && ts <= max) does tell for every value of the
    // parameter pack if it is between min and max (including min and max).
    return ((min <= ts && ts <= max) && ...);
}

int main()
{
    std::cout << "within( 10, 20, 1, 15, 30) returns false: " << std::boolalpha << within( 10, 20, 1, 15, 30) << std::endl;
    std::cout << "within( 10, 20, 11, 12, 13) returns true: " << std::boolalpha << within( 10, 20, 11, 12, 13) << std::endl;
    std::cout << "within(5.0, 5.5, 5.1, 5.3) returns true: " << std::boolalpha << within(5.0, 5.5, 5.1, 5.3) << std::endl;

    std::string aaa {"aaa"};
    std::string bcd {"bcd"};
    std::string def {"def"};
    std::string zzz {"zzz"};
    std::cout << "within(aaa, zzz, bcd, def) returns true: " << std::boolalpha << within(aaa, zzz, bcd, def) << std::endl;
    std::cout << "within(aaa, def, bcd, zzz) returns false: " << std::boolalpha << within(aaa, def, bcd, zzz) << std::endl;
}