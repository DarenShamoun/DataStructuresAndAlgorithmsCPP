#pragma once

#include <iosfwd>
#include <string>

#include "Animal.h"

struct Owl : public Animal {

    std::string name()       const override { return "hootie"; }
    std::string make_sound() const override { return "Hoot!"; }

    void  fly()
    {
      // do cool night flying things
    }

};

std::ostream& operator<<(std::ostream& os, const Owl& rhs);

