#include "Animal.h"
#include "Cat.h"
#include "Chicken.h"
#include "Cow.h"
#include "Dog.h"
#include "Opera.h"

#include <vector>

void sing_a_lot(const Animal& animal, unsigned int times) {
    while (times-- > 0)
    { animal.sing(' '); }
    animal.sing('\n');
}

void sing_chorus(std::vector<Animal*>& chorus) {
    for (const auto animal : chorus)
    { animal->sing('\n'); }
    std::cout << std::endl;
}

int main() {

    Opera opera;
    opera.sing();

    Cat     cat;
    Chicken chicken;
    Dog     dog;
    Cow     cow;

    std::vector<Animal*> chorus { &cat, &dog, &chicken };
    sing_chorus(chorus);

    sing_a_lot(cat, 2u);
    sing_a_lot(dog, 1u);
    sing_a_lot(cow, 3u);
    sing_a_lot(dog, 1u);
    sing_a_lot(chicken, 2u);

    return 0;
}
