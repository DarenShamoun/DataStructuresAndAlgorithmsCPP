#pragma once 

#include <string>

class Animal {

  public:
    virtual ~Animal() = default;

    virtual std::string make_sound() const = 0;

    virtual std::string name() const = 0;

};

