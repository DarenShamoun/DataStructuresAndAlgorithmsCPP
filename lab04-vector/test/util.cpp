
#include <iostream>
#include <vector>

#include "util.h"

namespace std {
  std::ostream& operator<<(std::ostream& os, const std::vector<int>& rhs)
    {
      os << '[';
      for (const auto& e: rhs) {
        os << e;
        if (&e != &rhs.back()) os << ',';
      }
      return os << ']';
    }
}

