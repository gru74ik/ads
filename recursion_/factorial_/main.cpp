#include <iostream>
#include <utility>

using Item = unsigned long long;

namespace sm
{
    template <Item n>
    struct factorial
    {
        static const Item value = n * factorial<n-1>::value;
    };

    template <>
    struct factorial<0>
    {
        static const Item value = 1;
    };

}

namespace my
{
    Item iterative_factorial(Item n) {
        Item result = 1;
        for(Item i = 1; i <= n; ++i)
            result *= i;
        return result;
    }

    Item recursive_factorial(Item n) {
        if (n == 0 || n == 1)
            return 1;
        return n * recursive_factorial(n - 1);
    }

    constexpr Item constexpr_factorial(Item n) {
        return (n == 0) || n == 1 ? 1 : n * constexpr_factorial(n - 1);
    }
}

namespace fe
{
    //Calculate factorial using fold expression:
    template <class T, T N, class I = std::make_integer_sequence<T, N>>
    struct factorial;

    template <class T, T N, T... Ints>
    struct factorial<T, N, std::integer_sequence<T, Ints...>> {
        static constexpr T value = (static_cast<T>(1) * ... * (Ints + 1));
    };
}


int main()
{
    std::cout << my::iterative_factorial(4) << std::endl;
    std::cout << my::recursive_factorial(5) << std::endl;
    std::cout << my::constexpr_factorial(6)  << std::endl;
    std::cout << fe::factorial<Item, 7>::value << std::endl;
    std::cout << sm::factorial<8>::value << std::endl;
}

/*
n	n!
0	1
1	1
2	2
3	6
4	24
5	120
6	720
7	5040
8	40320
9	362880
10	3628800
11	39916800
12	479001600
13	6227020800
14	87178291200
15	1307674368000
16	20922789888000
17	355687428096000
18	6402373705728000
19	121645100408832000
20	2432902008176640000
*/