#pragma once
#include "Phone.h"

#include <iostream>
class HomePhone : public Phone
{
public:
    HomePhone(const Person& ppl, int position)
        : Phone { ppl }
        , _position { position } {}
    void ring() const override {
        if (_position != _owner.get_position())
        {
            std::cout << "This is the voicemail of" << _owner.get_name() << "Please leave a message."
                      << std::endl;
            return;
        }
        _owner.answer_phone();
    }

private:
    int _position = 0;
};