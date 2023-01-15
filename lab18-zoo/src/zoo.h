#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "Animal.h"
#include "Pet.h"

std::vector<Pet*> make_pets();

void play_with_pets(const std::vector<Pet*>&, const int16_t);

std::vector<std::unique_ptr<Animal>> make_animals();

void treat_animals(const std::vector<std::unique_ptr<Animal>>&);

