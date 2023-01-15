#ifndef MESA_CISC187_LAB6_UTIL_H
#define MESA_CISC187_LAB6_UTIL_H

#include <iostream>
#include <vector>

#include <lab6.h>

namespace std {
  std::ostream& operator<<(std::ostream& os, const mesa::trigon& rhs);

  std::ostream& operator<<(std::ostream& os, const std::vector<mesa::trigon>& rhs);
}

#endif

