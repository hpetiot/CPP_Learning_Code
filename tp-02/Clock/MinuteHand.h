#pragma once

class MinuteHand
{
private:
    unsigned int _minutes = 0;

public:
    unsigned int get_minutes() const;
    void         advance();
};