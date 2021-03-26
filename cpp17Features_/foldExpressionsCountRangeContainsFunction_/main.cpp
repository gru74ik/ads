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
    std::vector<int> v {1, 2, 3, 4, 5};
    std::cout
        << "matches(v, 2, 5) returns " << matches(v, 2, 5) << std::endl // returns 2 
        << "matches(v, 100, 200) returns " << matches(v, 100, 200) << std::endl // returns 0
        << "matches(\"abcdefg\", 'x') returns " << matches("abcdefg", 'x') << std::endl // returns 0
        << "matches(\"abcdefg\", 'a', 'd', 'f') returns " << matches("abcdefg", 'a', 'd', 'f') << std::endl; // returns 3
}