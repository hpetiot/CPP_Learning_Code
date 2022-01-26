#include "PC.h"

#include "Trainer.h"

#include <iostream>

void PC::give_back(Trainer& trainer, const std::string& name) {
    for (size_t i = 0; i <= _pokemons.size(); i++)
    {
        if (_pokemons[i]->name() == name && _pokemons[i]->trainer()->name() == trainer.name())
        {
            trainer.capture(std::move(_pokemons[i]));
            _pokemons.erase(_pokemons.begin() + i);
            break;
        }
        return;
    }
}