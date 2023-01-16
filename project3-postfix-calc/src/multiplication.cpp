//Daren Shamoun
//ID# 5550016094
#include "big_number_calculator.h"
#include "operation.h"

//define multiplication operation
class Multiplication : public Operation
{
public:
    std::vector<int> handle(const std::vector<int>& operands) const override
    {
        // Make sure there are exactly two operands
        if (operands.size() != 2)
        {
            throw std::invalid_argument("Multiplication requires exactly two operands");
        }

        // Check if one of the operands is zero
        if (operands[0].size() == 1 && operands[0][0] == 0)
        {
            return { 0 };
        }
        if (operands[1].size() == 1 && operands[1][0] == 0)
        {
            return { 0 };
        }

        const std::vector<int>& multiplicand = operands[0];
        const std::vector<int>& multiplier = operands[1];

        std::vector<int> product(multiplicand.size() + multiplier.size(), 0);
        for (int i = 0; i < multiplicand.size(); i++)
        {
            int carry = 0;
            for (int j = 0; j < multiplier.size() || carry > 0; j++)
            {
                const int digit = j < multiplier.size() ? multiplier[j] : 0;
                const int sum = product[i + j] + multiplicand[i] * digit + carry;
                product[i + j] = sum % 10;
                carry = sum / 10;
            }
        }

        // Remove leading zeros
        product.erase(std::find_if(product.rbegin(), product.rend(),
            [](int digit) { return digit != 0; }).base(), product.end());
        return product;
    }

    size_t GetOperandCount() const override
    {
        return 2;
    }

    std::unique_ptr<Operation> Clone() const override
    {
        return std::make_unique<Multiplication>(*this);
    }
};