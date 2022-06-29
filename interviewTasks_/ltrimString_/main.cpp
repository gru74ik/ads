#include <iostream>
#include <string>
#include <algorithm>

// This function trims leading spaces in given string
std::string ltrim(std::string & s) {
    // using remove-erase idiom:
    s.erase(std::remove(s.begin(), s.end(),' '), s.end());
    return s;
}

template <typename T>
void print(const T & sequence, const std::string & delimiter) {
    for (const auto & elem : sequence) {
        std::cout << elem << delimiter;
    }
    std::cout << '\n';
}

int main() {
    std::string s("      1234");
    std::cout << "s.size(): " << s.size() << '\n';
    print(s, "");
    std::cout << "ltrim(s).size(): " << ltrim(s).size() << '\n';
    print(s, "");
}