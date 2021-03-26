/*
Обычная лямбда-функция:
[]( int x ) { return x > 0; }

Синтаксис хвостового возвращаемого типа:
[]( double x )->double
{
    int y = x;
    return x - y;
}
возвращаемый тип - double.
Нужен, если в теле лямбды больше одного statement'a

Доступ по значению и ссылке.
Доступ к переменной addition по значению:
[addition](int x) { return x + y; }

Доступ к переменной sum по ссылке:
[&sum](int x) { return x + y; }

Доступ ко всем переменным по значению:
[=](){ return cats + dogs; }

Доступ ко всем переменным по ссылке:
[&](){ return cats + dogs; }

Доступ к cats по значению, а к dogs по ссылке:
[cats, &dogs](){ return cats + dogs; }

Доступ к dogs по ссылке, а ко всем остальным переменным по значению:
[=, &dogs](){ return cats + dogs; }

Доступ к cats по значению, а ко всем остальным переменным по ссылке:
[&, cats](){ return cats + dogs; }
*/

#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
    int arr[] = { 30, 15, 58, 33, 42, 11, 99, 58 };

    std::cout << "Number of elements multiples of three: " <<
        std::count_if
            (
                std::begin( arr ),
                std::end( arr ),
                []( int x ) { return x % 3 == 0; }
            );

    return 0;
}