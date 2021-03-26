/*
Предикаты - функции и функциональные объекты, возвращающие bool.
Предикат не должен иметь состояния.
То есть, предикат не должен изменять своего состояния, вследствие
вызова, а копия предиката должна иметь то же состояние, что и оригинал.
Оператор() должен быть объявлен константным - это поможет
предотвратить изменение состояния предиката.
*/

#include <iostream>
#include <iterator>

auto is_odd( int number )
{
    return number % 2;
}

class Pred
{
public:
    bool operator() ( int number ) const // const тут очень важен!
    {
        return !( number % 2 );
    }
} IsEven;

template <typename InputIterator, typename Predicate>
unsigned int count_if
    (
        InputIterator first,
        InputIterator last,
        Predicate pred
    )
{
    unsigned int n = 0;
    for ( ; first < last; ++first )
        if ( pred( *first ) )
            ++n;
    return n;
}

template<typename MyVeryAwesomeType>
void show( const MyVeryAwesomeType& arr )
{
    for ( const auto & elem : arr )
        std::cout << elem << " ";
}

int main()
{
    int arr[] = { -1, 2, -3, -4, -5, 6, 7, -8, -9 };

    show (arr);

    std::cout
        << "\n\nTotal amount of odd elements: "
        << count_if( std::begin( arr ), std::end( arr ), is_odd );

    std::cout
        << "\n\nTotal amount of even elements: "
        << count_if( std::begin( arr ), std::end( arr ), IsEven );

    std::cout
        << "\n\nTotal amount of negative elements: "
        << count_if( std::begin( arr ), std::end( arr ), []( int n ) { return n < 0; } );

    auto is_positive = []( int n ) { return n > 0; };
    std::cout
        << "\n\nTotal amount of positive elements: "
        << count_if( std::begin( arr ), std::end( arr ), is_positive );
}