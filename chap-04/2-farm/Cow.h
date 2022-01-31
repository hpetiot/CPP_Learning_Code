#pragma once

#include <iostream>

class Cow : public Animal
{
public:
    void sing(char spacing) const override { std::cout << "Mewwwwwh" << spacing; }
};
