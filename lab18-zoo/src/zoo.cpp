#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "Owl.h"
#include "Wolf.h"
#include "Pet.h"
#include "RoboDog.h"

#include "zoo.h"

std::vector<Pet*> make_pets()
{
	std::vector<Pet*> pets;
	pets.push_back(new Cat());
	pets.push_back(new Dog());
	pets.push_back(new Fish());
	pets.push_back(new RoboDog());
	return pets;
}

void play_with_pets(const std::vector<Pet*>& petVector, const int16_t times)
{
	for (auto pet : petVector)
	{
		for (int16_t i = 0; i < times; ++i)
		{
			pet->play();
		}
	}
}

std::vector<std::unique_ptr<Animal>> make_animals()
{
	std::vector<std::unique_ptr<Animal>> animals;
	animals.push_back(std::make_unique<Cat>());
	animals.push_back(std::make_unique<Dog>());
	animals.push_back(std::make_unique<Owl>());
	animals.push_back(std::make_unique<Wolf>());
	return animals;
}

void treat_animals(const std::vector<std::unique_ptr<Animal>>& animalVector)
{
	for (auto& animal : animalVector)
	{
		std::cout << animal->make_sound() << '\n';
	}
}