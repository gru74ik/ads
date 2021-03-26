#include <vector>
#include <memory>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "Tank.h"
#include "TankFactory.h"

void example1() //without patterns
{
    std::srand(time(0));
    using uptr = std::unique_ptr<BaseTank>;
    std::vector<uptr> tanks;

    for (int i = 0, numberOfTanks = (std::rand() % 10) + 1; i < numberOfTanks; ++i)
    {
        int rval = std::rand() % 2;
        switch (rval)
        {
            case 0:
            {
                tanks.push_back(std::make_unique<T72>());
                break;
            }
            case 1:
            {
                tanks.push_back(std::make_unique<M1Abrams>());
                break;
            }
        }
    }

    for (const auto & tank : tanks)
    {
        tank.get()->draw();
    } 
}

void example2()
{
    std::srand(time(0));
    using uptr = std::unique_ptr<BaseTank>;
    std::vector<uptr> tanks;

    for (int i = 0, numberOfTanks = (std::rand() % 10) + 1; i < numberOfTanks; ++i)
    {
        int rval = std::rand() % 2;
        switch (rval)
        {
            case 0:
            {
                static ConcreteTankFactory<T72> t72;
                tanks.push_back(t72.make_tank());
                break;
            }
            case 1:
            {
                static ConcreteTankFactory<M1Abrams> m1;
                tanks.push_back(m1.make_tank());
                break;
            }
        }
    }

    for (const auto & tank : tanks)
    {
        tank.get()->draw();
    }
}

int main()
{
    //example1();
    example2();
}