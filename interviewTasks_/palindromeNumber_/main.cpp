#include <iostream>
#include <vector>
#include <cmath>
class Solution
{
public:
    bool isPalindrome(int x)
    {
        bool result = true;
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            result = false;
        }
        else {
            for (int revertedNum = 0; x > revertedNum; result = x == revertedNum || x == revertedNum / 10) {
                revertedNum = revertedNum * 10 + x % 10;
                x /= 10;
            }            
        }
        return result;
    }
};

int main ()
{
    Solution x;
    std::cout << std::boolalpha
        << "x.isPalindrome(-1) expected result: false.\nActual result: " << x.isPalindrome(-1) << "\n\n"
        << "x.isPalindrome(2147483647) expected result: false.\nActual result: " << x.isPalindrome(2147483647) << "\n\n"
        << "x.isPalindrome(1230) expected result: false.\nActual result: " << x.isPalindrome(1230) << "\n\n"
        << "x.isPalindrome(0) expected result: true.\nActual result: " << x.isPalindrome(0) << "\n\n"
        << "x.isPalindrome(12021) expected result: true.\nActual result: " << x.isPalindrome(12021) << "\n\n"
        << "x.isPalindrome(10001) expected result: true.\nActual result: " << x.isPalindrome(10001) << "\n\n";

    return 0;
}