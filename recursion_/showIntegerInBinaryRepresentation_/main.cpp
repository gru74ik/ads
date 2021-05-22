#include <iostream>

void showReversedBinary(int n)
{
    if (n == 0) { return; }  // base case
    std:: cout << (n%2);
    showReversedBinary(n/2); // recursive call with another arg
}

void showForwardBinary(int n)
{
    if (n == 0) { return; } // base case
    showForwardBinary(n/2); // recursive call with another arg
    std::cout << (n%2);
}

int main()
{
    showForwardBinary(187);
    std::cout << std::endl;
    showReversedBinary(187);
    std::cout << std::endl;
}