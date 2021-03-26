#include <iostream>
#include <string>
#include <utility>

struct Person
{
    int age_ = 0;
    std::string name_;
};

int main()
{
    Person ms = { 42, "Jim" };
    auto&& [age, name] = std::move(ms); // entity is rvalue reference to ms

    std::cout << "ms.age_: " << ms.age_ << '\n'; // prints 42
    std::cout << "ms.name_: " << ms.name_ << '\n'; // prints "Jim"

    std::cout << "age: " << age << '\n'; // prints 42
    std::cout << "name: " << name << '\n'; // prints "Jim"
}
