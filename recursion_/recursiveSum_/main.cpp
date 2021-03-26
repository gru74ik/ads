#include <iostream>
#include <list>

using Item = int;

Item recursiveSum(std::list<Item> & list) {
    Item result = 0;
    if (!list.empty()) {
        if (list.size() == 1)
        {
            result = list.front();
        }
        else {
            result = list.front();
            list.pop_front();
            result += recursiveSum(list);
        }
    }
    return result;
}

int main()
{
    std::list<Item> myList {1, 2, 4, 6};
    std::cout << "Sum of elements of the list is: " << recursiveSum(myList) << "\n\n";
}
