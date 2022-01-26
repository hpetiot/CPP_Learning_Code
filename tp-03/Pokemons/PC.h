#pragma once
#include "Pokemon.h"

#include <utility>
#include <vector>
// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class Trainer;
class PC
{
private:
    std::vector<std::unique_ptr<Pokemon>> _pokemons;

public:
    const std::vector<std::unique_ptr<Pokemon>>& pokemons() const { return _pokemons; }
    void receive(std::unique_ptr<Pokemon> pokemon) { _pokemons.push_back(std::move(pokemon)); }
    void give_back(Trainer& trainer, const std::string& name);
};
