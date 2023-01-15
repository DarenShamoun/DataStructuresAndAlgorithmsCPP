#pragma once

class Robot {

  public:
    virtual ~Robot() = default;

    virtual int charge_remaining() const = 0;
};

