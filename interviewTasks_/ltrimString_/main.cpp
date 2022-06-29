#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

std::string ltrim(std::string &s) {
    s.erase(
        s.begin(),
        std::find_if(
            s.begin(),
            s.end(),
            [](char ch) { return !std::isspace(ch); }
        )
    );
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
    std::string s(" 1234");
    std::cout << "s.size(): " << s.size() << '\n';
    print(s, "");
    std::cout << "ltrim(s).size(): " << ltrim(s).size() << '\n';
    print(s, "");
}