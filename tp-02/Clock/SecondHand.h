#pragma once

#include "MinuteHand.h"
class SecondHand
{
private:
    unsigned int _seconds = 0;
    MinuteHand&  _minutes;

public:
    SecondHand(MinuteHand&);
    unsigned int get_seconds() const;
    void         advence();
};