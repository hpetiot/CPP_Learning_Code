#pragma once
#include "MinuteHand.h"
#include "SecondHand.h"

#include <ostream>

class Clock
{
private:
    MinuteHand _m;
    SecondHand _s { _m };

public:
    Clock();
    void                 tick();
    friend std::ostream& operator<<(std::ostream&, const Clock&);
};