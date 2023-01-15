
#include <iostream>
#include <vector>

#include "util.h"

namespace std {

std::ostream& operator<<(std::ostream& os, const mesa::trigon& rhs)
{
  return os << '{' << rhs.a << ',' << rhs.b << ',' << rhs.c << '}';
}


std::ostream& operator<<(std::ostream& os, const std::vector<mesa::trigon>& rhs)
{
  os << '[';
  for (const auto& e: rhs) {
    os << e;
    if (&e != &rhs.back()) os << ',';
  }
  return os << ']';
}

} // end std namespace

