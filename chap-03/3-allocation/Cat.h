#pragma once

#include <iostream>
#include <string>

class Cat
{
    friend std::ostream& operator<<(std::ostream& stream, const Cat& cat) {
        return stream << "I have a cat named " << cat.name << ".";
    }

public:
    Cat(const std::string& name)
        : name { name } {}
    ~Cat() { std::cout << name << " est mort!" << std::endl; }
    bool operator==(const Cat& other) const { return name == other.name; }

private:
    std::string name;
};