#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string &s, char delim) {
    std::stringstream ss(s);
    std::vector<std::string> words;
    for (std::string word; std::getline(ss, word, delim); ) {
        words.push_back(word);
    }
    return words;
}

int main()
{
    std::string text = "DON'T WORRY BE HAPPY";
    auto words = split(text, ' ');
    
    for (const auto & word : words) {
        std::cout << word << "\n";
    }
}