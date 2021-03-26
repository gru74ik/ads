#ifndef BASETANK_H
#define BASETANK_H

#include <iostream>
#include <string>

class BaseTank //abstract base class 
{
public:
    virtual void draw() = 0;
    virtual ~BaseTank() = default;
};

class M1Abrams : public BaseTank //concrete class
{
public:
    M1Abrams(const std::string& country = "USA") : m_country(country) {}
    void draw() override
    {
        std::cout << "I am heavy tank M1 Ambrams (" << m_country << ")\n";
    }
private:
    std::string m_country;
};

class T72 : public BaseTank //concrete class
{
public:
    T72(const std::string& country = "USSR") : m_country(country) {}
    void draw() override
    {
        std::cout << "I am heavy tank T72 (" << m_country << ")\n";
    }
private:
    std::string m_country;
};

#endif //BASETANK_H