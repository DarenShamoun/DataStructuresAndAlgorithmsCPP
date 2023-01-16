//Daren Shamoun
//ID# 5550016094
#include "big_number_calculator.h"
#include "operation.h"

//define subtraction operation
class Subtraction : public Operation
{
public:
    std::vector<int> handle(const std::vector<int>& operands) const override
    {
        // Make sure there are exactly two operands
        if (operands.size() != 2)
        {
            throw std::invalid_argument("Subtraction requires exactly two operands");
        }

        const std::vector<int>& minuend = operands[0];
        const std::vector<int>& subtrahend = operands[1];

        // Check if the minuend is smaller than the subtrahend
        if (minuend.size() < subtrahend.size() ||
            (minuend.size() == subtrahend.size() && std::lexicographical_compare(minuend.rbegin(), minuend.rend(), subtrahend.rbegin(), subtrahend.rend())))
        {
            // If the minuend is smaller than the subtrahend, swap the operands and negate the result
            std::vector<int> difference;
            int borrow = 0;
            for (int i = 0; i < subtrahend.size(); i++)
            {
                const int a = i < minuend.size() ? minuend[i] : 0;
                const int b = i < subtrahend.size() ? subtrahend[i] : 0;
                int diff = b - a - borrow;
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
            difference.front() *= -1;
            // Remove leading zeros
            difference.erase(std::find_if(difference.rbegin(), difference.rend(), [](int digit) { return digit != 0; }).base(), difference.end());
            return difference;
        }

        // If the minuend is not smaller than the subtrahend, subtract the subtrahend from the minuend
        std::vector<int> difference;
        int borrow = 0;
        for (int i = 0; i < minuend.size(); i++)
        {
            const int a = i < minuend.size() ? minuend[i] : 0;
            const int b = i < subtrahend.size() ? subtrahend[i] : 0;
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
        return difference;
    }

    size_t GetOperandCount() const override
    {
        return 2;
    }

    std::unique_ptr<Operation> Clone() const override
    {
        return std::make_unique<Subtraction>(*this);
    }
};