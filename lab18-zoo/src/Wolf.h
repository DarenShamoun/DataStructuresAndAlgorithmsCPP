#pragma once

#include <iosfwd>
#include <string>

#include "Canine.h"

class Wolf : public Canine {

  public:
    Wolf() : name_{"White Fang"} {}
    std::string name()             const override { return name_; }
    std::string make_sound()       const override { return "Woo woo woooooooo!"; }
    bool        is_domesticated()  const override { return false; }

  private:
    std::string name_;

};

std::ostream& operator<<(std::ostream& os, const Wolf& rhs);

