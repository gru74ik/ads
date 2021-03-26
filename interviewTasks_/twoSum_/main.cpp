// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

std::pair<int, int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> result;
    for (int i = 0, diff; const auto elem : nums) {
        diff = target - elem;           
        if (result.count(diff)) {
            return { result[diff], i };
        }
        result[elem] = i++;
    }
    return { 0, 1 };
}

struct Test
{
    Test() = default;
    Test(std::vector<int> v, int t) : ivec(v), target(t) {}
    std::vector<int> ivec;
    int target;
};

int main()
{
    std::vector<Test> tests {
        {{2, 7, 11, 15}, 9},
        {{3, 2, 4}, 6},
        {{3, 3}, 6},
    };

    for (auto& test : tests) {
        auto [first_index, second_index] = twoSum(test.ivec, test.target);
        std::cout << first_index << ", " << second_index << "\n";
    }
}