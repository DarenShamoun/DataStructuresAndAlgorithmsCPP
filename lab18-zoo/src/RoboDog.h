#pragma once

#include <iostream>
#include <string>

#include "Pet.h"
#include "Robot.h"

class RoboDog : public Pet, public Robot {

  public:
    RoboDog() :name_{"Robie"}, charge_{100}, friendly_{true}
  {}
    std::string name()             const override { return name_; }
    int         charge_remaining() const override { return charge_; }
    bool        is_friendly()      const override { return friendly_; }

    void play() override;

  private:
    std::string  name_;
    int  charge_;
    bool friendly_;

};

std::ostream& operator<<(std::ostream& os, const RoboDog& r);

