// https://www.hackerrank.com/challenges/sparse-arrays/problem

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <iterator>

std::vector<int> matchingStrings(std::vector<std::string> strings, std::vector<std::string> queries) {
    std::vector<int> result;
    std::unordered_multiset<std::string> ms(strings.begin(), strings.end());
    for (const auto & query : queries) {
        result.push_back(ms.count(query));
    }
    return result;
}

class Test
{
public:
    Test() = default;
    Test(
        const std::vector<std::string> & strings,
        const std::vector<std::string> & queries,
        const std::vector<int> & results)
        : m_strings(strings)
        , m_queries(queries)
        , m_results(results)
    {}

    void run() const {
        std::cout << (is_passed() ? "PASSED\n" : "FAILED\n");
    }

private:
    std::vector<std::string> m_strings;
    std::vector<std::string> m_queries;
    std::vector<int> m_results;

    bool is_passed() const {
        auto res = matchingStrings(m_strings, m_queries);
        if (res.size() != m_results.size()) {
            return false;
        }
        for (auto it = res.begin(); const auto & elem : m_results) {
            if (*it != elem) {
                return false;
            }
            it = std::next(it, 1);
        }
        return true;
    }
};

int main()
{
    std::vector<Test> tests {
        {
            {"abcde", "sdaklfj", "asdjf", "na", "basdn", "sdaklfj", "asdjf", "na", "asdjf", "na", "basdn", "sdaklfj", "asdjf"},
            {"abcde", "sdaklfj", "asdjf", "na", "basdn"},
            {1, 3, 4, 3, 2}            
        },
        {
            {"def", "de", "fgh"},
            {"de", "lmn", "fgh"},
            {1, 0, 1}
        },
        {
            {"aba", "baba", "aba", "xzxb"},
            {"aba", "xzxb", "ab"},
            {2, 1, 0}
        },
        {
            {"abaq", "babaq", "qaba", "qxzxb"},
            {"aba", "xzxb", "ab"},
            {2, 1, 0}
        },
        {
            {"you", "ball", "love", "ally", "alan", "you", "was", "love", "hall", "you", "all", "is", "al", "as", "is", "live"},
            {"all", "you", "need", "is", "love"},
            {1, 3, 0, 2, 2}
        },
    };

    for (const auto & test : tests) {
        test.run();
    }
}