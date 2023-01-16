//Daren Shamoun
//ID# 5550016094
#include "big_number_calculator.h"
#include "operation.h"

//define addition operation
class Addition : public Operation
{
public:
    // Override the base class's handle() function
    std::vector<int> handle(const std::vector<int>& operands) const override
    {
        std::vector<int> result;
        int carry = 0;
        size_t i = 0;
        for (; i < operands.size() / 2; i++)
        {
            const int digit1 = operands[i];
            const int digit2 = operands[i + operands.size() / 2];
            const int sum = digit1 + digit2 + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
        }
        if (operands.size() % 2 == 1)
        {
            result.push_back(operands[i] + carry);
        }
        else if (carry > 0)
        {
            result.push_back(carry);
        }
        return result;
    }
};