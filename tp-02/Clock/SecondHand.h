#pragma once

#include "MinuteHand.h"
class SecondHand
{
private:
    int         _seconds = 0;
    MinuteHand& _minutes;

public:
    SecondHand(MinuteHand&);
    int  get_seconds() const;
    void advence();
};