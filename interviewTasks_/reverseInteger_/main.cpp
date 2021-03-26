#include <iostream>
#include <cmath>
#include <algorithm>
#include <exception>

int32_t reverseInt(int32_t x) {
    auto s = std::to_string(x);
    std::reverse(s.begin(), s.end());
    try {
        x = x < 0 ? -std::stoi(s) : std::stoi(s);
    }
    catch(const std::out_of_range& oor) {
        x = 0;
    }
    return x;
}

int main () {
    std::cout << reverseInt(123456789) << "\n\n";
}