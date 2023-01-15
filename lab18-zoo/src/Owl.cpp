#include "Owl.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Owl& rhs)
{
  return os << rhs.make_sound();
}

