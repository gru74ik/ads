//aabbbaa =3
//bfff =3
//ababab = 1
//h = 1
//"" = 0
//aaaaccaaггрр = 4


#include <iostream>
#include <cstddef>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

std::size_t count_max_consecutive_repeating_char(const std::string & str) {
    if (str.empty()) { return 0; }
    if (str.size() == 1) { return 1; }
    
    std::set<std::size_t> res;
    std::size_t counter = 0;
    
    for (char consec_repeat_char = str.front(); const auto ch : str) {
        if (ch == consec_repeat_char) {
            ++counter;
        }
        else {
            res.insert(counter);
            counter = 1;
            consec_repeat_char = ch;
        }
    }
    res.insert(counter);

    return *res.rbegin();
}

class Test
{
public:
    Test() = default;
    Test(
        const std::vector<std::string> & samples,
        std::vector<std::pair<std::size_t, std::size_t>> & results)
        : m_samples(samples)
        , m_results(results)
    {}

    void run() {
        for (std::size_t i = 0; const auto & smpl : m_samples) {
            m_results[i++].second = count_max_consecutive_repeating_char(smpl);
        }
        show_results();
    }

private:
    std::vector<std::string> m_samples;
    std::vector<std::pair<std::size_t, std::size_t>> m_results;

    void show_results() const {
        for (const auto & [expected, actual] : m_results) {
            std::cout
                << "EXPECTED: " << expected << ", "
                << "ACTUAL: " << actual << ". "
                << (actual == expected ? "TEST PASSED.\n" : "TEST FAILED.\n");
        }
        std::cout << "\n";
    }
};

int main()
{
    std::vector<std::string> samples {
        "aabbbaa", "bfff", "ababab", "h", "", "aaaaccaarrpp"};
        
    std::vector<std::pair<std::size_t, std::size_t>> results {
        {3, 0}, {3, 0}, {1, 0}, {1, 0}, {0, 0}, {4, 0}};
        
    Test test(samples, results);
    test.run();
}
