#include <iostream>
#include <vector>
#include <utility>

template <typename T>
class Solution {
public:
    using IndexT = std::size_t;
    using ResultT = std::pair<IndexT, IndexT>;
    using DataT = std::vector<T>;

    static ResultT getHappyInterval(const DataT & data) {
        if (data.empty()) {
            return {}; //TODO: maybe would be better to throw exception?
        }

        T prevSum = data.front();
        IndexT lowerBound {};
        IndexT upperBound {};
        T sum {};
        int pos = -1;
        for (IndexT i {}; i < data.size(); ++i) {
            sum += data[i];
            if (sum > prevSum) {
                prevSum = sum;
                lowerBound = static_cast<IndexT>(pos + 1);
                upperBound = i;
            }
            if (sum < 0) {
                sum = 0;
                pos = i;
            }
        }

        return {lowerBound, upperBound};
    }
};

template <typename T>
class TestFramework {
public:
    using IndexT = std::size_t;
    using ResultT = std::pair<IndexT, IndexT>;
    using DataT = std::vector<T>; 

    void runTests() {
        for (IndexT i = 0; const auto & testCase : m_testCases) {
            const auto & actual = Solution<T>::getHappyInterval(testCase);
            if (m_expected[i] == actual) {
                std::cout << "\x1B[32mPASSED:\033[0m "; //Word "PASSED" will be green (under Linux)
            }
            else {
                std::cout << "\x1B[31mFAILED:\033[0m "; //Word "FAILED" will be red (under Linux)
            }
            std::cout
                << "expected: ["
                << m_expected[i].first << " ,"
                << m_expected[i].second << "], actual: "
                << "[" << actual.first << " ," << actual.second << "]\n";
            ++i;
        }
    }
private:
    std::vector<DataT> m_testCases{
        {9, -4, 5, 9, 1, 1},    //A1: [9, -4, 5, 9, 1, 1]     => [0, 5] //calc whole range
        {9, -4, -4, 9, 9, 1},   //A2: [9, -4, -4, 9, 9, 1]    => [0, 5] //calc whole range
        {9, -3, 2, -4, 9, 1},   //A3: [9, -3, 2, -4, 9, 1]    => [0, 5] //calc whole range
        {9, -9, -9, -9, -9, -9},//B1: [9], -9, -9, -9, -9, -9 => [0, 0] //discard right
        {9, -9, -9, 1, 2, 1},   //B2: [9], -9, -9, 1, 2, 1    => [0, 0] //discard right
        {9, -9, -9, -9, 8, 1},  //B3: [9], -9, -9, -9, 8, 1   => [0, 0] //discard right
        {9, -8, 9, -5, -5, -5}, //B4: [9, -8, 9], -5, -5, -5  => [0, 2] //discard right
        {9, 9, -5, -1, -2, -9}, //B5: [9, 9], -5, -1, -2, -9  => [0, 1] //discard right
        {9, 9, -9, 5, 3, 1},    //B6: [9, 9], -9, 5, 3, 1     => [0, 1] //discard right
        {-9, -9, -9, -9, -9, 9},//C1: -9, -9, -9, -9, -9, [9] => [5, 5] //discard left
        {-9, -9, -9, -9, 9, 9}, //C2: -9, -9, -9, -9, [9, 9]  => [4, 5] //discard left
        {-9, -9, 5, -1, 5, 5},  //C3: -9, -9, [5, -1, 5, 5]   => [2, 5] //discard left
        {8, -9, 5, -1, 5, 5},   //C4: 8, -9, [5, -1, 5, 5]    => [2, 5] //discard left
        {-9, -9, 9, -2, -1, 9}, //C5: -9, -9, [9, -2, -1, 9]  => [2, 5] //discard left
        {-1, -2, 1, 2, -9, 9},  //C6: -1, -2, 1, 2, -9, [9]   => [5, 5] //discard left
        {5, 1, -7, 9, -9, -1},  //D1: 5, 1, -7, [9], -9, -1   => [3, 3] //discard left & right
        {5, -9, 3, 3, -9, -1},  //D2: 5, -9, [3, 3], -9, -1   => [2, 3] //discard left & right
        {5, -9, 7, -1, 8, -9},  //D3: 5, -9, [7, -1, 8], -9   => [2, 4] //discard left & right
        {5, -9, 3, 3, -9, 5}    //D4: 5, -9, [3, 3], -9, 5    => [2, 3] //discard left & right
    };

    std::vector<ResultT> m_expected {
        {0, 5},
        {0, 5},
        {0, 5},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 2},
        {0, 1},
        {0, 1},
        {5, 5},
        {4, 5},
        {2, 5},
        {2, 5},
        {2, 5},
        {5, 5},
        {3, 3},
        {2, 3},
        {2, 4},
        {2, 3}
    };
};

int main() {
    TestFramework<int> t;
    t.runTests();
}