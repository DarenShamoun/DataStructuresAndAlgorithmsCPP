#pragma once

#include <iosfwd>
#include <string>

#include "Pet.h"
#include "Animal.h"

class Cat : public Pet, public Animal {

  public:
    Cat() :name_{"Fluffy"}, friendly_{true}
  {}
    std::string name()             const override { return name_; }
    std::string make_sound()       const override { return "meow."; }
    bool        is_friendly()      const override { return friendly_; }

    void play() override;

  private:
    std::string  name_;
    bool friendly_;

};

std::ostream& operator<<(std::ostream& os, const Cat& rhs);

