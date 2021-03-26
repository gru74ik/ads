#include <iostream>
#include <string>

template <typename ... Ts>
auto sum(Ts ... ts)
{
    return (ts + ...); //unary left fold expands to 1 + (2 + (3 + (4 + 5))) 
}

int main()
{
    int sum_of_integers {sum(1, 2, 3, 4, 5)};
    std::cout << "sum_of_integers: " << sum_of_integers << std::endl;

    std::string a {"Hello "};
    std::string b {"World"};
    std::cout << "sum of strings: " << sum(a, b) << '\n';
}
