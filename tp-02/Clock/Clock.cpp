#include "Clock.h"

#include <iostream>

Clock::Clock() {
    _m = MinuteHand();
}

void Clock::tick() {
    _s.advence();
}

std::ostream& operator<<(std::ostream& stream, const Clock& clock) {
    return stream << clock._m.get_minutes() << " min " << clock._s.get_seconds() << " sec";
}

int main() {
    Clock c;
    for (int i = 0; i < 63; i++)
    { c.tick(); }
    std::cout << c << std::endl;
}