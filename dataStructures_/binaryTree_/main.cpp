#include "BinaryTree.h"

int main()
{
    BinaryTree<int> myTree1;
    std::cout << "default ctor has been called. "
        "New size of myTree1: " << myTree1.size() << std::endl;
    std::cout << "Now myTree1 is: ";
    myTree1.print();

    myTree1.insert(777);
    std::cout << "insert() has been called. "
        "New size of myTree1: " << myTree1.size() << std::endl;
    std::cout << "Now myTree1 is: ";
    myTree1.print();

    myTree1.clear();
        std::cout << "clear() has been called. "
        "New size of myTree1: " << myTree1.size() << std::endl;
    std::cout << "Now myTree1 is: ";
    myTree1.print();

    myTree1.insert(5);
    std::cout << "insert() has been called. "
        "New size of myTree1: " << myTree1.size() << std::endl;
    std::cout << "Now myTree1 is: ";
    myTree1.print();

    myTree1.clear();
        std::cout << "clear() has been called. "
        "New size of myTree1: " << myTree1.size() << std::endl;
    std::cout << "Now myTree1 is: ";
    myTree1.print();


    BinaryTree<int> myTree(4);
    std::cout << "ctor has been called. "
        "New size of myTree: " << myTree.size() << std::endl;
    std::cout << "Now myTree is: ";
    myTree.print();

    myTree.insert(5);
    std::cout << "insert() has been called. "
        "New size of myTree: " << myTree.size() << std::endl;
    std::cout << "Now myTree is: ";
    myTree.print();

    myTree.insert(3);
    std::cout << "insert() has been called. "
        "New size of myTree: " << myTree.size() << std::endl;
    std::cout << "Now myTree is: ";
    myTree.print();

    myTree.insert(1);
    std::cout << "insert() has been called. "
        "New size of myTree: " << myTree.size() << std::endl;
    std::cout << "Now myTree is: ";
    myTree.print();

    myTree.insert(2);
    std::cout << "insert() has been called. "
        "New size of myTree: " << myTree.size() << std::endl;
    std::cout << "Now myTree is: ";
    myTree.print();

    myTree.insert(2);
    std::cout << "insert() has been called. "
        "New size of myTree: " << myTree.size() << std::endl;
    std::cout << "Now myTree is: ";
    myTree.print();
}