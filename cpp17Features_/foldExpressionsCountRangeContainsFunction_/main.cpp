#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// a function that tells whether some range contains values we provide
// as variadic parameters and count the number of these values:
template <typename R, typename ... Ts>
auto matches(const R& range, Ts ... ts)
{
    return (std::count(std::begin(range), std::end(range), ts) + ...);
}

int main() {
    std::vector<int> ivec {1, 2, 3, 4, 5};
    std::cout
        << "matches(ivec, 2, 5) returns " << matches(ivec, 2, 5) // returns 2 
        << "\nmatches(ivec, 100, 200) returns " << matches(ivec, 100, 200) // returns 0
        << "\nmatches(\"abcdef\", 'x') returns " << matches("abcdef", 'x') // returns 0
        << "\nmatches(\"kisses\", 's') returns " << matches("kisses", 's') // returns 3
        << "\n";
}