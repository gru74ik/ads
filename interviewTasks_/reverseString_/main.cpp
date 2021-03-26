#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

namespace my
{
    template <typename BidirectionalIterator>
    void reverse1(BidirectionalIterator first, BidirectionalIterator last)
    {
        while ((first != last) && (first != --last))
        {
            std::iter_swap(first++, last);
        }
    }

    template <typename T >
    void reverse2(T& a)
    {
        for (typename T::size_type i = 0, j = a.size() - 1, half = a.size() / 2; i < half; ++i)
        {
            std::swap(a[i], a[j - i]);
        }
    }
}


int main()
{
    std::string s1 = "DOOM GOD";
    std::cout << "Display in console reversed string but don't reverse string itself: ";
    std::copy(s1.crbegin(), s1.crend(), std::ostream_iterator<char>(std::cout, "")); //expected output: DOG MOOD

    std::string s2 = "RAW ROOM";
    std::cout << "\nReverse string itself using std::reverse and display it in console: ";
    std::reverse(s2.begin(), s2.end());
    std::cout << s2; //expected output: MOOR WAR

    std::string s3 = "NET DAM";
    std::cout << "\nReverse string itself using my::reverse1 and display it in console: ";
    my::reverse1(s3.begin(), s3.end());
    std::cout << s3; //expected output: MAD TEN

    std::string s4 = "STAR LIVE";
    std::cout << "\nReverse string itself using my::reverse2 and display it in console: ";
    my::reverse2(s4);
    std::cout << s4 << "\n\n"; //expected: EVIL RATS
}