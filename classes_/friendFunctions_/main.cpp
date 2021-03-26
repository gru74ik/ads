/*
Дружественные функции (friend functions).

Три разновидности друзей:
• дружественные функции (friend functions);
• дружественные классы (friend classes);
• дружественные функции-члены (friend member functions).


Функция-друг класса: привилегии доступа как у функций-членов.
Сферы применения: перегрузка бинарной операции.
В реализации добавлять квалификатор ClassName:: не нужно.
Ключевое слово friend  в объявлении друга.
*/
#include <iostream>
#include <string>

class Animal
{
private:
    std::string kind_;
    std::string name_;
    unsigned int number_of_legs_;

public:
    Animal() :
        kind_( "some animal" ),
        name_( "nameless" ),
        number_of_legs_( 4 )
    {}

    Animal
        (
            std::string kind,
            std::string name,
            unsigned int number_of_legs
        ) :
        kind_( kind ),
        name_( name ),
        number_of_legs_( number_of_legs )
    {}

    // друг класса Animal
    friend std::ostream & operator<<( std::ostream & os, const Animal & a )
    {
        os
            << a.kind_
            << " "
            << a.name_
            << "\n";

        return os;
    }
};


int main()
{
    Animal m( "Cat", "Musya", 3 );
    Animal p( "Cat", "Plushka", 4 );

    std::cout << m << p;
}