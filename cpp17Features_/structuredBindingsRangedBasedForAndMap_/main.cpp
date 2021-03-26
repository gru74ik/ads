#include <iostream>
#include <string>
#include <map>

struct Person
{
    int age{ 0 };
    std::string name{ "Unnamed person" };
};

Person getPersonInfo()
{
    return Person{ 33, "Nadezhda" };
}

int main()
{
    Person person{ 42, "Rodion" };
    //The exact behavior of an initialization
    auto [personAge, personName] = person;
    // behaves as if we’d initialize a new entity e with person and let the structured bindings personAge
    // and personName become alias names for the members of this new object, similar to defining:
    // auto e = person;
    // aliasname personAge = e.age;
    // aliasname personName = e.name;
    std::cout //prints the values of e.age and e.name, which are copies of person.age and person.name
        << "Person age: " << personAge
        << "\nPerson name: " << personName;

    auto [person_age, person_name] = getPersonInfo();
    std::cout
        << "\n\nPerson age: " << person_age
        << "\nPerson name: " << person_name;

    if (person_age > 30)
    {
        std::cout << "\n\nThe chosen person is " << person_name;
    }
    std::cout << "\n\n";

    for (std::map<std::string, int> mymap; const auto & [a, n] : mymap)
    {
        std::cout
            << "\n\nPerson age: " << a
            << "\nPerson name: " << n;
    }
}