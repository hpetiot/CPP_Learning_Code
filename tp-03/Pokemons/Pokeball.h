#pragma once

#include "Pokemon.h"

#include <memory>
#include <utility>
// A ball where Pokemon sleep.
class Pokeball
{
private:
    std::unique_ptr<Pokemon> _pokemon {};

public:
    bool               empty() const { return _pokemon == nullptr; }
    void               store(std::unique_ptr<Pokemon> incoming) { _pokemon = std::move(incoming); }
    /*const*/ Pokemon& pokemon() const { return *_pokemon; }
    void               transfer_to_pc(PC& pc) { pc.receive(std::move(_pokemon)); }
};