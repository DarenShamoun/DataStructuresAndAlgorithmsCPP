#include "Fish.h"
#include <iostream>

void Fish::play() 
{
  std::cout << "swim ...\n";
}

int Fish::change_bouyancy(const int percent)
{
  bouyancy_ += percent;
  return bouyancy_;
}

std::ostream& operator<<(std::ostream& os, const Fish& rhs)
{
  return os << rhs.make_sound();
}

