#include <iostream>
#include <iomanip>
#include <tuple>
#include <functional>
#include <string>
#include <list>


static void print_student(std::size_t id, const std::string & name, double gpa) {
    std::cout
        << "Student" << std::quoted(name)
        << ", ID: " << id
        << ", GPA: " << gpa << "\n";
}

int main()
{
    using Student = std::tuple<std::size_t, std::string, double>;
    Student john {123, "John Doe", 3.7};

    {
        const auto & [id, name, gpa] = john;
        print_student(id, name, gpa);
    }
    std::cout << "-----\n";

    using namespace std::string_literals;
    auto students = {
        std::make_tuple(234, "Denis Black"s, 3.7),
        std::make_tuple(345, "Billy White"s, 4.1),
        std::make_tuple(456, "Cathy Green"s, 3.5),
    };

    for (const auto & [id, name, gpa] : students) {
        print_student(id, name, gpa);
    }
    std::cout << "-----\n";

    for (const auto & student : students) {
        std::apply(print_student, student);
    }
    std::cout << "-----\n";
}