#include <iostream>
#include <optional>

using OptInt = std::optional<int>;

OptInt read_int()
{
    int i;
    if (std::cin >> i) {
        return {i};
    }
    return {};
}

OptInt operator+(OptInt a, OptInt b) {
    if (!a || !b) {
        return {};
    }
    return {*a + *b};
}

OptInt operator+(OptInt a, int b) {
    if (!a) {
        return {};
    }
    return {*a + b};
}

int main()
{
    std::cout << "Please enter 2 integers.\n";
    auto a {read_int()};
    auto b {read_int()};
    auto sum {a + b + 10};
    if (sum) {
        std::cout << *a << " + " << *b << " + 10 = " << *sum << '\n';
    }
    else {
        std::cout << "sorry, the input was something else than 2 integers.\n";
    }
}