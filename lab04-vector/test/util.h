#ifndef MESA_CISC187_LAB_UTIL_H
#define MESA_CISC187_LAB_UTIL_H

#include <iostream>
#include <vector>


namespace std {
  std::ostream& operator<<(std::ostream& os, const std::vector<int>& rhs);
}

#endif

