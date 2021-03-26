#include <iostream>
#include <string>

template <typename ... Ts>
auto product(Ts ... ts) {
    return (ts * ... * 1);
}

int main() {
    int product_of_integers {product(1, 2, 3, 4, 5)};
    std::cout << "product_of_integers: " << product_of_integers << std::endl;
}