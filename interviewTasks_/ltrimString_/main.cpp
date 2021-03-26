#include <iostream>
#include <string>
#include <cctype>

std::string ltrim(const std::string &str)
{
    std::string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); }));
    return s;
}

int main()
{
    std::string s(" 1234");
    std::cout << s.size() << std::endl;
    std::cout << ltrim(s).size() << std::endl;
}