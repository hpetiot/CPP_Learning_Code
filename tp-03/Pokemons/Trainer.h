#pragma once
#include "PC.h"
#include "Pokeball.h"
#include "Pokemon.h"

#include <memory>
#include <utility>
#include <vector>

// A person that capture Pokemons and make them fight.
class Trainer
{

public:
    Trainer(std::string name, PC& pc)
        : _name { name }
        , _pc { pc } {}

    void capture(std::unique_ptr<Pokemon> pokemon) {
        pokemon->set_trainer(this);
        for (size_t i = 0u; i < _pokeballs.size(); i++)
        {
            if (_pokeballs[i].empty())
            {
                _pokeballs[i].store(std::move(pokemon));
                return;
            }
        }
        _pc.receive(std::move(pokemon));
    }
    void                            store_in_pc(int index) { _pokeballs[index].transfer_to_pc(_pc); }
    const std::string&              name() const { return _name; }
    const std::array<Pokeball, 6u>& pokeballs() const { return _pokeballs; }

private:
    std::string              _name;
    PC&                      _pc;
    std::array<Pokeball, 6u> _pokeballs;
};
