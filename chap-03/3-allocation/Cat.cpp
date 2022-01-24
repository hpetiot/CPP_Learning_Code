#include "Cat.h"

#include <memory>
#include <ostream>
int main() {
    std::unique_ptr<Cat> kitty_ptr = std::make_unique<Cat>("Pop");
    std::cout << *kitty_ptr << std::endl;

    std::unique_ptr<Cat> schroedinger;

    if (nullptr == schroedinger)
    { std::cout << "Box openned: cat is dead" << std::endl; }

    schroedinger = std::make_unique<Cat>("Schroedinger");

    if (kitty_ptr == schroedinger)
    { std::cout << "kitty = schroedinger" << std::endl; }
    if (*kitty_ptr == *schroedinger)
    { std::cout << "they are the same cat !!!" << std::endl; }

    kitty_ptr.reset();
    if (nullptr == kitty_ptr)
    { std::cout << "une eutanasie à été nécéssaire." << std::endl; }
    return 0;
}