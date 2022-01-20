#pragma once
#include "../Event.h"
#include "MinuteHand.h"
#include "SecondHand.h"

#include <iostream>
#include <ostream>
#include <vector>
class Clock
{
private:
    MinuteHand         _m;
    SecondHand         _s { _m };
    std::vector<Event> _events;

public:
    Clock();
    Clock(const std::vector<Event>&);
    void                 tick();
    void                 add_event(const Event&);
    friend std::ostream& operator<<(std::ostream&, const Clock&);
};