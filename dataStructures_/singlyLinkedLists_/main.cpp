#include "LinkedList.h"

int main()
{
    LinkedList<int> myList(100);
    std::cout << "ctor has been called. "
        "New size of myList: " << myList.size() << std::endl;
    std::cout << "Now myList is: ";
    myList.print();

    myList.push_back(200);
    std::cout << "push_back() has been called. "
        "New size of myList: " << myList.size() << std::endl;
    std::cout << "Now myList is: ";
    myList.print();

    myList.push_back(300);
    std::cout << "push_back() has been called. "
        "New size of myList: " << myList.size() << std::endl;
    std::cout << "Now myList is: ";
    myList.print();

    std::cout << "The third element of myList is: ";
    std::cout << myList[2] << std::endl;

    myList[2] = 777;
    std::cout << "The third element of myList after assignment is: ";
    std::cout << myList[2] << std::endl;
    std::cout << "Now myList is: ";
    myList.print();

    myList.pop_front();
    std::cout << "pop_front() has been called. "
        "New size of myList: " << myList.size() << std::endl;
    std::cout << "Now myList is: ";
    myList.print();

    myList.clear();
    std::cout << "clear() has been called. "
        "New size of myList: " << myList.size() << std::endl;
    std::cout << "Now myList is: ";
    myList.print();

    for (const auto elem : {11, 22, 33, 44})
    {
        myList.push_back(elem);
    }
    std::cout << "push_back() has been called 4 times. "
        "New size of myList: " << myList.size() << std::endl;
    std::cout << "Now myList is: ";
    myList.print();
}
