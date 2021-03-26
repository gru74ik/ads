#include <iostream>
#include <vector>
#include <algorithm>

int sockMerchant(std::vector<int> ar) {
    int number_of_pairs = 0;
    while (ar.size() > 1) {
        int last = ar.back();
        ar.pop_back();
        auto iter = std::find(ar.begin(), ar.end(), last);
        if (iter != ar.end()) {
            number_of_pairs++;
            ar.erase(iter);   
        }
    }
    return number_of_pairs;
}

int main()
{
    std::vector<int> socks{11, 20, 20, 11, 44, 37, 50, 44, 20};
    int result = sockMerchant(socks);
    std::cout << result << std::endl;
}
