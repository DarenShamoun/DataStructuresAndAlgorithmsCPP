#include "Cat.h"
#include <iostream>

void Cat::play() 
{
  std::cout << "cuddle, purr ...\n";
}

std::ostream& operator<<(std::ostream& os, const Cat& rhs)
{
  return os << rhs.make_sound();
}

