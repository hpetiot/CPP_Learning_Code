#pragma once

#include <iostream>

class Dog : public Animal
{
public:
    void sing(char spacing) const override { std::cout << "Waf" << spacing; }
};
