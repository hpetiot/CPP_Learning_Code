#pragma once

class MinuteHand
{
private:
    int _minutes = 0;

public:
    int  get_minutes() const;
    void advance();
};