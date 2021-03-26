#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <vector>

class Car
{
struct Dimension;
public:
    Car() = default;

    Car(const std::string& brand,
        const std::string& model,
        const std::string& engine,
        const std::string& bodyStyle,
        const std::string& transmission,
        unsigned year,
        unsigned topSpeed,
        double acceleration,
        const std::vector<Dimension>& dimensions)
        :
        m_brand(brand),
        m_model(model),
        m_engine(engine),
        m_bodyStyle(bodyStyle),
        m_transmission(transmission),
        m_year(year),
        m_topSpeed(topSpeed),
        m_acceleration(acceleration),
        m_dimensions(dimensions)
    {}

    void set(const std::string& brand,
        const std::string& model,
        const std::string& engine,
        const std::string& bodyStyle,
        const std::string& transmission,
        unsigned year,
        unsigned topSpeed,
        double acceleration,
        const std::vector<Dimension>& dimensions)
    {
        m_brand = brand;
        m_model = model;
        m_engine = engine;
        m_bodyStyle = bodyStyle;
        m_transmission = transmission;
        m_year = year;
        m_topSpeed = topSpeed;
        m_acceleration = acceleration;
        m_dimensions.clear();
        m_dimensions = dimensions;
    }

    friend std::ostream& operator<<(std::ostream& os, const Car& car)
    {
        os
            << car.m_brand << " " << car.m_model << " (" << car.m_year
            << "):\n\tAcceleration 0 - 100 km/h: " << car.m_acceleration << " s"
            << "\n\tTop speed: " << car.m_topSpeed << "km/h\n";
        return os;
    }

private:
    struct Dimension
    {
        std::string m_name;
        double m_value;
    };

    std::string m_brand;
    std::string m_model;
    std::string m_engine;
    std::string m_bodyStyle;
    std::string m_transmission;
    unsigned m_year;
    unsigned m_topSpeed;
    double m_acceleration;
    std::vector<Dimension> m_dimensions;
};

#endif //CAR_H