#include "MinuteHand.h"

#include <iostream>

unsigned int MinuteHand::get_minutes() const {
    return _minutes;
}

void MinuteHand::advance() {
    _minutes += 1;
}
/*
int main() {
    MinuteHand m1;

    m1.advance();
    std::cout << m1.get_minutes() << std::endl;
    m1.advance();
    std::cout << m1.get_minutes() << std::endl;
    return 0;
}*/