#pragma once

// A creature that is cute and can fight other ones.
class Trainer;
class Pokemon
{
private:
    std::string _name;
    Trainer*    _trainer = nullptr;

public:
    Pokemon(std::string name)
        : _name { name } {}
    const std::string& name() const { return _name; }
    void               set_trainer(Trainer* trainer) { _trainer = trainer; }
    const Trainer*     trainer() const { return _trainer; }
};
