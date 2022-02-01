#pragma once

#include "Person.h"

class Phone
{
public:
    virtual void ring() const = 0;

protected:
    Phone(const Person& owner)
        : _owner { owner } {}
    virtual ~Phone() {};
    const Person& _owner;
};
