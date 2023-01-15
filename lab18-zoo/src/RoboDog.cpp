#include "RoboDog.h"
#include <iostream>

void RoboDog::play() 
{
  std::cout << "beep!\n";
  --charge_;
}

std::ostream& operator<<(std::ostream& os, const RoboDog& r)
{
  return os << "Charge remaining: " << r.charge_remaining();
}

