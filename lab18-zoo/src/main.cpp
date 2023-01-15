// add includes required for std library facilities needed
#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

#include "zoo.h"
#include "Robot.h"
#include <RoboDog.h>

int main () 
{
  // declare a vector of raw pointers of Pet objects
  // using make_pets()

	std::vector<Pet*> pets = make_pets();
	

  // write a loop that plays with all the pets

	play_with_pets(pets, 1);
	
  // write a loop that plays with the RoboDog 5 more times
  // and then prints the charge remaining
  // - Do not make a new RoboDog.
  // - Use the RoboDog in pets

	for (auto pet : pets)
	{
		if (pet->name() == "Robie")
		{
			for (int16_t x = 0; x < 5; ++x)
			{
				pet->play();
			}
			RoboDog* robo = dynamic_cast<RoboDog*>(pet);
			std::cout << "Charge remaining: " << robo->charge_remaining() << std::endl;
		}
	}

  // cleanup pet vector memory

	for (auto pet : pets)
	{
		delete pet;
	}

  // declare a vector of unique_ptr pointers of Animal objects
  // using make_animals()
  // give each animal a shot

	auto animals = make_animals();
	treat_animals(animals);
  
	return 0;
}



