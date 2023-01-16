//Daren Shamoun
//ID# 5550016094
#include "big_number_calculator.h"
#include "operation.h"

//define division operation
class Division : public Operation
{
public:
    std::vector<int> handle(const std::vector<int>& operands) const override
    {
        // Make sure there are exactly two operands
        if (operands.size() != 2)
        {
            throw std::invalid_argument("Division requires exactly two operands");
        }

        const std::vector<int>& dividend = operands[0];
        const std::vector<int>& divisor = operands[1];

        // Check if the dividend is smaller than the divisor
        if (dividend.size() < divisor.size() ||
            (dividend.size() == divisor.size() && std::lexicographical_compare(dividend.rbegin(), dividend.rend(), divisor.rbegin(), divisor.rend())))
        {
            // If the dividend is smaller than the divisor, return a result of 0
            return { 0 };
        }

        // Perform long division
        std::vector<int> quotient;
        std::vector<int> remainder = dividend;
        while (remainder.size() >= divisor.size())
        {
            int digit = 0;
            while (std::lexicographical_compare(divisor.rbegin(), divisor.rend(), remainder.rbegin(), remainder.rend()))
            {
                // Subtract the divisor from the remainder
                std::vector<int> difference;
                int borrow = 0;
                for (int i = 0; i < remainder.size(); i++)
                {
                    const int a = i < remainder.size() ? remainder[i] : 0;
                    const int b = i < divisor.size() ? divisor[i] : 0;
                    int diff = a - b - borrow;
                    if (diff < 0)
                    {
                        borrow = 1;
                        diff += 10;
                    }
                    else
                    {
                        borrow = 0;
                    }
                    difference.push_back(diff);
                }
                // Remove leading zeros
                difference.erase(std::find_if(difference.rbegin(), difference.rend(), [](int digit) { return digit != 0; }).base(), difference.end());
                remainder = std::move(difference);
                digit++;
            }
            quotient.push_back(digit);
            remainder.resize(remainder.size() - divisor.size());
        }
        // Remove leading zeros
        quotient.erase(std::find_if(quotient.rbegin(), quotient.rend(), [](int digit) { return digit != 0; }).base(), quotient.end());
        return quotient;
    }

    size_t GetOperandCount() const override
    {
        return 2;
    }

    std::unique_ptr<Operation> Clone() const override
    {
        return std::make_unique<Division>(*this);
    }
};