#include "SecondHand.h"

#include <iostream>

SecondHand::SecondHand(MinuteHand& minutes)
    : _minutes { minutes } {
}

int SecondHand::get_seconds() const {
    return _seconds;
}

void SecondHand::advence() {
    if (_seconds == 59)
    {
        _minutes.advance();
        _seconds = 0;
    }
    else
    { _seconds += 1; }
}
/*
int main() {
    MinuteHand m;
    SecondHand s { m };

    for (int i = 0; i < 90; i++)
    { s.advence(); }
    std::cout << "Il s'est écoulé " << m.get_minutes() << "minutes et " << s.get_seconds() << "secondes"
              << std::endl;
    return 0;
}*/