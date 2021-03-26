#include <iostream>
#include <string>
#include <cctype>

std::string rtrim(const std::string &str)
{
    std::string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
    return s;
}

int main()
{
    std::string s("1234 ");
    std::cout << s.size() << std::endl;
    std::cout << rtrim(s).size() << std::endl;
}