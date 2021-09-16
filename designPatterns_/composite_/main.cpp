#include <iostream>
#include <vector>
#include <cassert>
#include <memory>

// Component
class Unit
{
public:
    virtual ~Unit() = default;

    virtual int getStrength() const = 0;

    virtual void addUnit(std::unique_ptr<Unit> p)
    {
        assert(false);
    }
};

// Primitives
class Archer : public Unit
{
public:
    int getStrength() const override
    {
        return 1;
    }
};

class Infantryman : public Unit
{
public:
    int getStrength() const override
    {
        return 2;
    }
};

class Horseman : public Unit
{
public:
    int getStrength() const override
    {
        return 3;
    }
};

// Composite
class CompositeUnit : public Unit
{
public:
    int getStrength() const override
    {
        int total = 0;
        for (const auto & elem : m_compositeUnit)
            total += elem->getStrength();
        return total;
    }

    void addUnit(std::unique_ptr<Unit> p) override
    {
        m_compositeUnit.push_back(std::move(p));
    }

private:
    std::vector<std::unique_ptr<Unit>> m_compositeUnit;
};

// Helper-function to create legions
auto createLegion()
{
    constexpr std::size_t NUMBER_OF_INFATRYMEN_IN_ROMAN_ARMY = 3000;
    constexpr std::size_t NUMBER_OF_ARCHERS_IN_ROMAN_ARMY = 1200;
    constexpr std::size_t NUMBER_OF_HORSEMEN_IN_ROMAN_ARMY = 300;

    std::unique_ptr<Unit> legion = std::make_unique<CompositeUnit>();

    for (std::size_t i = 0; i < NUMBER_OF_INFATRYMEN_IN_ROMAN_ARMY; ++i) {
        legion->addUnit(std::make_unique<Infantryman>());
    }

    for (std::size_t i = 0; i < NUMBER_OF_ARCHERS_IN_ROMAN_ARMY; ++i) {
        legion->addUnit(std::make_unique<Archer>());
    }

    for (std::size_t i = 0; i < NUMBER_OF_HORSEMEN_IN_ROMAN_ARMY; ++i) {
        legion->addUnit(std::make_unique<Horseman>());
    }

    return legion;
}

int main()
{
    constexpr std::size_t NUMBER_OF_LEGIONS_IN_ROMAN_ARMY = 4;

    std::unique_ptr<Unit> army = std::make_unique<CompositeUnit>();
    for (std::size_t i = 0; i < NUMBER_OF_LEGIONS_IN_ROMAN_ARMY; ++i) {
        army->addUnit(createLegion());
    }
    std:: cout << "Roman army damaging strength is " << army->getStrength() << "\n\n";
}