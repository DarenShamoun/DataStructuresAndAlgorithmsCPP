#pragma once

#include <string>

#include "Animal.h"

class Canine : public Animal {

  public:
    ~Canine() override = default;
    std::string make_sound() const override {
      return "woof!";
    }
    virtual bool is_domesticated() const = 0;

};

