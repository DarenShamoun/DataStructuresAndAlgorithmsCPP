#pragma once

#include <iosfwd>
#include <string>

#include "Pet.h"
#include "Animal.h"

class Fish : public Pet, public Animal {

  public:
    Fish() :name_{"Jaws"}, friendly_{false}, bouyancy_{0}
  {}
    std::string name()             const override { return name_; }
    std::string make_sound()       const override { return "bubble . . ."; }
    bool        is_friendly()      const override { return friendly_; }

    void play() override;
    int  change_bouyancy(const int percent);

  private:
    std::string  name_;
    bool friendly_;
    int bouyancy_;

};

std::ostream& operator<<(std::ostream& os, const Fish& rhs);

