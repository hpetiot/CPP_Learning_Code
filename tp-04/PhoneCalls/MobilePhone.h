#pragma once
#include "Phone.h"

class MobilePhone : public Phone
{
public:
    MobilePhone(Person ppl)
        : Phone { ppl } {}
    void ring() const override { _owner.answer_phone(); }
};