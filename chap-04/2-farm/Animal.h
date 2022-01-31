#pragma once

#include <iostream>

class Animal
{
public:
    virtual ~Animal() {};
    virtual void sing(char spacing) const { std::cout << "..." << spacing; }
};
