// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int> & nums, int target) {
    std::unordered_map<int, int> result;
    for (int i = 0, diff = 0; const auto elem : nums) {
        diff = target - elem;           
        if (auto found = result.find(diff); found != result.end() && found->second != i) {
            return { result[diff], i };
        }
        result[elem] = i++;
    }
    return { -1, -1 };
}

class Test
{
public:
    Test() = default;
    Test(const std::vector<int> & v, int t) : m_integers(v), m_target(t) {}
    std::vector<int> & integers() { return m_integers; }
    int target() { return m_target; }

    void run() const {
        std::cout << (is_passed() ? "PASSED\n" : "FAILED\n");
    }

private:
    std::vector<int> m_integers;
    int m_target;

    bool is_passed() const {
        auto res = twoSum(m_integers, m_target);
        return res.front() != -1 && m_target == m_integers.at(res.front()) + m_integers.at(res.back());
    }
};

int main()
{
    std::vector<Test> tests {
        {{2, 7, 11, 15}, 9},
        {{3, 2, 4}, 6},
        {{3, 45, 4, 9, 10, 33, 21}, 19},
        {{1, 2, 5, 32, 99, 20, 12, 70}, 71},
        {{78, 13, 54, 77, 89, 43, 2, 99, 25}, 56},
        {{3, 4}, 7},
        {{3, 4, 6, 8, 60, 50, 40}, 99},
    };

    for (const auto & test : tests) {
        test.run();
    }
}