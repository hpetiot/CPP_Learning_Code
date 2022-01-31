#pragma once

#include <iostream>

class Cat : public Animal
{
public:
    void sing(char spacing) const override { std::cout << "Meow" << spacing; }
};
