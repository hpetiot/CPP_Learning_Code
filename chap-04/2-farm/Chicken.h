#pragma once

#include <iostream>

class Chicken : public Animal
{
public:
    ~Chicken() override { std::cout << "CotCoooot" << std::endl; }
    void sing(char spacing) const override { std::cout << "Cotcotcotcodet" << spacing; }
};
