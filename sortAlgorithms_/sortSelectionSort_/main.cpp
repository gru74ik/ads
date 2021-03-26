#include <iostream>
#include <vector>
#include <algorithm>

using Item = int;

void selectionSort(std::vector<Item> & vec) {
    std::vector<Item> newVec;
    for (auto & elem : vec) {
        auto minElem = std::min_element(vec.begin(), vec.end());
        newVec.push_back(*minElem);
        vec.erase(minElem, minElem + 1);
    }
    vec.resize(newVec.size());
    std::copy(newVec.begin(), newVec.end(), vec.begin());
}

int main()
{
    std::vector<int> vec {34, 32, 56, 12, 90, 36};
    selectionSort(vec);

    std::cout << "This is your sorted vector:\n";
    for (const auto elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}
