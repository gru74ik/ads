#include <iostream>
#include <string>

void staircase(int n) {
    for (std::string s(n-1, ' '), h(1, '#');
        n--;
        s.pop_back(), h.push_back('#')) {
        std::cout << s << h << '\n';        
    }
}

int main()
{
    staircase(6);
}