//In given string find lengths of non-overlapping substrings
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>

int main()
{
    std::string s("ababcbacadefegdehijhklij");
    std::vector<std::pair<std::size_t, std::size_t>> bounds;

    for (std::set<char> occuredCharacters; auto ch : s) {
        if (!occuredCharacters.contains(ch)) {
            occuredCharacters.insert(ch);
            auto lowerBound = s.find_first_of(ch);
            auto upperBound = s.find_last_of(ch);
            if (bounds.empty() || lowerBound > bounds.back().second) {
                bounds.push_back({lowerBound, upperBound});
            }
            else if (upperBound > bounds.back().second) {
                bounds.back().second = upperBound;
            }
        }
    }
    for (const auto & [lowerBound, upperBound] : bounds) {
        std::cout << upperBound - lowerBound + 1 << "\n";
    }
}
