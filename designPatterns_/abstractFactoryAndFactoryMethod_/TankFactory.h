#ifndef TANKFACTORY_H
#define TANKFACTORY_H

#include <memory>
#include "Tank.h"


class AbstractTankFactory
{
public:
    virtual std::unique_ptr<BaseTank> make_tank() = 0; //Factory Method
    virtual ~AbstractTankFactory() = default;
};

template <typename TankType>
class ConcreteTankFactory : public AbstractTankFactory
{
public:
    std::unique_ptr<BaseTank> make_tank() override //Factory Method
    {
        return std::make_unique<TankType>();
    }
};

#endif //TANKFACTORY_H