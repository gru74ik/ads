#include <iostream>
#include <string>

struct Person
{
    int age{ 0 };
    std::string name{ "Unnamed person" };
};

int main()
{
    Person person{ 42, "Rodion" };
    const auto& [person1Age, person1Name] = person; // a reference, so that personAge/personName refer to person.personAge/person.personName
    // both person1Age and person1Name are not declared as being references. This only specifies that the anonymous entity e is
    // a reference. person1Age and person1Name have the type of the members of person. With our initial declaration this means
    // that decltype(person1Age) is int and decltype(person1Name) is std::string.

    std::cout
        << "Person age: " << person1Age
        << "\nPerson name: " << person1Name;

    if (person1Age > 30)
    {
        std::cout << "\nThe chosen person is " << person1Name << "\n\n";
    }
}