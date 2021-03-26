#include <iostream>
#include <cstddef>
#include <cstring>
#include <algorithm>

namespace rek
{
    class string
    {
    public:
        string() : m_data(nullptr), m_size(0) {
            std::cout << "Default ctor has been called!\n";
        }

        string(const char* ptr) {
            std::cout << "User-defined ctor has been called!\n";
            m_size = std::strlen(ptr) + 1;
            m_data = new char[m_size];
            std::memcpy(m_data, ptr, m_size);
        }

        string(const string& that) {
            std::cout << "Copy ctor has been called!\n";
            m_size = std::strlen(that.m_data) + 1;
            m_data = new char[m_size];
            std::memcpy(m_data, that.m_data, m_size);
        }

        ~string() noexcept {
            std::cout << "Dtor has been called!\n";
            delete[] m_data;
        }

        string(string&& that) noexcept
            : string() {
            std::cout << "Move ctor has been called!\n";
            swap(*this, that);
        }

        string& operator=(string that) noexcept {
            std::cout << "Assignment operator has been called!\n";
            swap(*this, that);
            return *this;
        }

        friend void swap(string& first, string& second) noexcept {
            std::swap(first.m_size, second.m_size);
            std::swap(first.m_data, second.m_data);
        }

        friend std::ostream& operator<<(std::ostream& os, const string& str) {
            os << str.m_data;
            return os;
        }

    private:
        char* m_data;
        std::size_t m_size;
    };
}

int main() {
    rek::string str1("3. This is a simple instance of user-defined class string\n");
    std::cout << str1;

    rek::string str2("4. This is completely another string\n");
    str1 = str2;

    rek::string str3(std::move(str1));
    std::cout << str3;

    str2 = std::move(str1);
}