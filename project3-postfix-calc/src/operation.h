//Daren Shamoun
//ID# 5550016094
#include "big_number_calculator.h"

//virtual base class for operations
class Operation
{
public:
    virtual ~Operation() = default;
    virtual std::vector<int> handle(const std::vector<int>& operands) const = 0;
    virtual size_t GetOperandCount() const = 0;
    virtual std::unique_ptr<Operation> Clone() const = 0;
};