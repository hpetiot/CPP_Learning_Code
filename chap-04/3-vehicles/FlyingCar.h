#pragma once
#include "Car.h"

class FlyingCar : public Car
{
public:
    FlyingCar(const Driver& driver, unsigned int speed)
        : Car { driver, speed }
        , _flying_speed { 10u * speed } {}
    unsigned int drive() const override {
        if (_driver.has_air_licence())
        {
            std::cout << "shweesh!" << std::endl;
            return _flying_speed;
        }
        return Car::drive();
    }

private:
    unsigned int _flying_speed = 0;
};