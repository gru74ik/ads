#include <iostream>

class IllFormedBase
{
public:
    IllFormedBase()
    {
        std::cout << "Hello from IllFormedBase()\n";
    }

    ~IllFormedBase()
    {
        std::cout << "Hello from ~IllFormedBase()\n";
    }
};

class WellFormedBase
{
public:
    WellFormedBase()
    {
        std::cout << "Hello from WellFormedBase()\n";
    }

    virtual ~WellFormedBase()
    {
        std::cout << "Hello from ~WellFormedBase()\n";
    }
};

class IllFormedDerived : public IllFormedBase
{
public:
    IllFormedDerived()
    {
        std::cout << "Hello from IllFormedDerived()\n";
    }

    ~IllFormedDerived()
    {
        //Resource cleanup could be here
        std::cout << "Hello from ~IllFormedDerived()\n";
    }
};

class WellFormedDerived : public WellFormedBase
{
public:
    WellFormedDerived()
    {
        std::cout << "Hello from WellFormedDerived()\n";
    }

    virtual ~WellFormedDerived()
    {
        //Resource cleanup could be here
        std::cout << "Hello from ~WellFormedDerived()\n";
    }
};

int main()
{
    IllFormedBase* obj1 = new IllFormedDerived();
    delete obj1;

    std::cout << "\n";

    WellFormedBase* obj2 = new WellFormedDerived();
    delete obj2;
}
