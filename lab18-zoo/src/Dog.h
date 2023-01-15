#pragma once

#include <iosfwd>
#include <string>

#include "Pet.h"
#include "Canine.h"

class Dog : public Pet, public Canine {

  public:
    Dog() :name_{"Fido"}, friendly_{true}
  {}
    std::string name()             const override { return name_; }
    std::string make_sound()       const override { return "arf, arf!"; }
    bool        is_friendly()      const override { return friendly_; }
    bool        is_domesticated()  const override { return true; }

    void play() override;

  private:
    std::string  name_;
    bool friendly_;

};

std::ostream& operator<<(std::ostream& os, const Dog& rhs);

