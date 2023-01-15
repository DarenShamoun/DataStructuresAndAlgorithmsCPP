#include "Wolf.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Wolf& rhs)
{
  return os << rhs.make_sound();
}

