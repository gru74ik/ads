#include <iostream>
#include <set>
#include <string>

class Product
{
public:
    Product() = default;

    Product(int id, double price, std::string name) :
        m_id(id), m_price(price), m_name(name)
    {}

    bool operator <(const Product& p) const
    {
        return m_id < p.m_id;
    }

    friend std::ostream& operator<<(std::ostream& os, const Product& p)
    {
        os << p.m_id << ". " << p.m_name << " ($" << p.m_price << ").";
        return os;
    }

private:
    int m_id;
    double m_price;
    std::string m_name;
};

int main()
{
    Product
        a(34, 20.95, "bra"),
        b(12, 10.32, "shorts"),
        c(22, 33.99, "purse"),
        d(78, 58.22, "dress"),
        e(33, 80.56, "sneakers"),
        f(52, 11.76, "belt"),
        g(45, 41.28, "t-shirt");

    for (std::multiset<Product> msp{ a, b, c, d, e, f, g }; const auto& elem : msp)
    { 
        std::cout << elem << "\n";
    }
} 