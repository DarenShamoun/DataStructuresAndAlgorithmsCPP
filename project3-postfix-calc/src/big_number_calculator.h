//Daren Shamoun
//ID# 5550016094
#ifndef CISC187_MESA_BIG_NUMBER_CALCULATOR_H
#define CISC187_MESA_BIG_NUMBER_CALCULATOR_H

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <functional>
#include <unordered_set>

class Operation
{
public:
    virtual ~Operation() = default;
    virtual std::vector<int> handle(const std::vector<std::vector<int>>& operands) const = 0;
    virtual size_t GetOperandCount() const = 0;
    virtual std::unique_ptr<Operation> Clone() const = 0;
};

//define addition operation
class Addition : public Operation
{
public:
    std::vector<int> handle(const std::vector<std::vector<int>>& operands) const override
    {
        std::vector<int> result;
        int carry = 0;
        for (int i = 0; i < operands[0].size() || i < operands[1].size(); i++)
        {
            int digit1 = i < operands[0].size() ? operands[0][i] : 0;
            int digit2 = i < operands[1].size() ? operands[1][i] : 0;
            int sum = digit1 + digit2 + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry > 0)
        {
            result.push_back(carry);
        }
        return result;
    }

    size_t GetOperandCount() const override
    {
        return 2;
    }

    std::unique_ptr<Operation> Clone() const override
    {
        return std::make_unique<Addition>(*this);
    }
};

//define subtraction operation
class Subtraction : public Operation
{
public:
    std::vector<int> handle(const std::vector<std::vector<int>>& operands) const override
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
                int a = i < minuend.size() ? minuend[i] : 0;
                int b = i < subtrahend.size() ? subtrahend[i] : 0;
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
            int a = i < minuend.size() ? minuend[i] : 0;
            int b = i < subtrahend.size() ? subtrahend[i] : 0;
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

//define multiplication operation
class Multiplication : public Operation
{
public:
    std::vector<int> handle(const std::vector<std::vector<int>>& operands) const override
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
                int digit = j < multiplier.size() ? multiplier[j] : 0;
                int sum = product[i + j] + multiplicand[i] * digit + carry;
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

//define division operation
class Division : public Operation
{
public:
    std::vector<int> handle(const std::vector<std::vector<int>>& operands) const override
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
                    int a = i < remainder.size() ? remainder[i] : 0;
                    int b = i < divisor.size() ? divisor[i] : 0;
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

//define exponent operation
class Exponent : public Operation
{
public:
    std::vector<int> handle(const std::vector<std::vector<int>>& operands) const override
    {
        // Make sure there is exactly one operand and the exponent is a positive integer
        if (operands.size() != 1 || operands[0].size() != 1 || operands[0][0] <= 0)
        {
            throw std::invalid_argument("Exponent requires exactly one operand and a positive integer exponent");
        }

        const std::vector<int>& base = operands[0];
        int exponent = operands[0][0];

        // Perform exponentiation by repeated multiplication
        std::vector<int> result = { 1 };
        for (int i = 0; i < exponent; i++)
        {
            std::vector<int> product(result.size() + base.size(), 0);
            for (int i = 0; i < result.size(); i++)
            {
                for (int j = 0; j < base.size(); j++)
                {
                    product[i + j] += result[i] * base[j];
                }
            }
            int carry = 0;
            for (int i = 0; i < product.size(); i++)
            {
                product[i] += carry;
                carry = product[i] / 10;
                product[i] %= 10;
            }
            // Remove leading zeros
            product.erase(std::find_if(product.rbegin(), product.rend(), [](int digit) { return digit != 0; }).base(), product.end());
            result = std::move(product);
        }
        return result;
    }

    size_t GetOperandCount() const override
    {
        return 1;
    }

    std::unique_ptr<Operation> Clone() const override
    {
        return std::make_unique<Exponent>(*this);
    }
};

//the actual calculator
class BigNumberCalculator
{
private:
    std::vector<int> m_result;

    std::map<std::string, std::unique_ptr<Operation>> operations_;

    static bool IsOperator(const std::string& token)
    {
        static const std::unordered_set<std::string> operators = { "+", "-", "*", "/", "^" };
        return operators.count(token) > 0;
    }

    size_t GetOperandCount(const std::string& token)
    {
        return operations_.at(token)->GetOperandCount();
    }

    std::unique_ptr<Operation>&& GetOperation(const std::string& token)
    {
        return std::move(operations_[token]);
    }

    // Helper function to create a deep copy of an `Operation` object
    std::unique_ptr<Operation> CloneOperation(const std::unique_ptr<Operation>& operation)
    {
        return std::unique_ptr<Operation>(operation->Clone());
    }

public:
    BigNumberCalculator() = default;

    std::vector<int> GetResult() const
    {
        return m_result;
    }

    // Register an operation with the given symbol
    void RegisterOperation(std::string symbol, std::unique_ptr<Operation> operation)
    {
        operations_[symbol] = std::move(operation);
    }
    
    std::unique_ptr<Operation> CreateOperation(const std::string& token)
    {
        static const std::unordered_map<std::string, std::function<std::unique_ptr<Operation>()>> factory = 
        {
            { "+", []() { return std::make_unique<Addition>(); } },
            { "-", []() { return std::make_unique<Subtraction>(); } },
            { "*", []() { return std::make_unique<Multiplication>(); } },
            { "/", []() { return std::make_unique<Division>(); } },
            { "^", []() { return std::make_unique<Exponent>(); } },
        };

        auto it = factory.find(token);
        if (it == factory.end())
        {
            throw std::invalid_argument("Invalid operator");
        }
        return it->second();
    }

    std::vector<int> static ParseBigNumber(const std::string& number)
    {
        std::vector<int> bigNumber;
        for (char ch : number)
        {
            if (!isdigit(ch))
            {
                throw std::invalid_argument("Invalid number");
            }
            bigNumber.push_back(ch - '0');
        }
        std::reverse(bigNumber.begin(), bigNumber.end());
        return bigNumber;
    }
    
    // Calculate the result of the given expression
    void Calculate(const std::string& expression)
    {
        std::vector<std::vector<int>> operands;
        std::stack<std::unique_ptr<Operation>> operations;

        std::stringstream ss(expression);
        std::string token;
        while (ss >> token)
        {
            if (IsOperator(token))
            {
                auto operation = CreateOperation(token);

                // Pop the required number of operands from the operands stack
                size_t operandCount = operation->GetOperandCount();
                std::vector<std::vector<int>> operationOperands;
                operationOperands.reserve(operandCount);
                for (size_t i = 0; i < operandCount; i++)
                {
                    operationOperands.push_back(operands.back());
                    operands.pop_back();
                }
                std::reverse(operationOperands.begin(), operationOperands.end());

                // Perform the operation and push the result onto the operands stack
                std::vector<int> result = operation->handle(operationOperands);
                operands.push_back(result);

                // Push the operation onto the operations stack
                operations.push(std::move(operation));
            }
            else
            {
                // Parse the token as a big number and push it onto the operands stack
                operands.push_back(ParseBigNumber(token));
            }
        }

        // The result should be the only operand left on the stack
        if (operands.size() != 1)
        {
            throw std::invalid_argument("Invalid expression");
        }
        m_result = std::move(operands.front());
    }
  
    static bool IsOperand(const std::string& token)
    {
        return std::all_of(token.begin(), token.end(), ::isdigit);
    }
    
    std::vector<int> ToBigNumber(const std::string& number)
    {
        std::vector<int> big_number;
        for (const char& digit : number)
        {
            big_number.push_back(digit - '0');
        }
        return big_number;
    }

    std::string ToString() const
    {
        std::stringstream ss;
        for (int i = m_result.size() - 1; i >= 0; i--)
        {
            ss << m_result[i];
        }
        return ss.str();
    }

    std::vector<int> EvaluatePostfix(const std::vector<std::string>& postfix)
    {
        std::stack<std::vector<int>> operand_stack;
        for (const std::string& token : postfix)
        {
            if (IsOperator(token))
            {
                int operand_count = GetOperandCount(token);
                std::vector<std::vector<int>> operands;
                while (operand_count-- > 0)
                {
                    operands.push_back(operand_stack.top());
                    operand_stack.pop();
                }
                std::vector<int> result = GetOperation(token)->handle(operands);
                operand_stack.push(result);
            }
            else
            {
                operand_stack.push(ToBigNumber(token));
            }
        }
        return operand_stack.top();
    }

    // Copy constructor
    BigNumberCalculator(const BigNumberCalculator& other)
    {
        // Iterate over the other object's operations map and make a copy of each unique_ptr
        for (const auto& pair : other.operations_)
        {
            auto& symbol = pair.first;
            auto& operation = pair.second;
            operations_[symbol] = operation->Clone();
        }
    }
    
    // Move constructor
    BigNumberCalculator(BigNumberCalculator&& other) noexcept
        : operations_(std::move(other.operations_))
    {
        // The other object's operations map has been moved to this object, so clear it in the other object
        other.operations_.clear();
    }

    // Copy assignment operator
    BigNumberCalculator& operator=(const BigNumberCalculator& other)
    {
        // Make a copy of the other object's operations map
        std::map<std::string, std::unique_ptr<Operation>> operations;
        for (const auto& pair : other.operations_)
        {
            auto& symbol = pair.first;
            auto& operation = pair.second;
            operations[symbol] = operation->Clone();
        }

        // Assign the copy to this object's operations map
        operations_ = std::move(operations);
        return *this;
    }

    // Move assignment operator
    BigNumberCalculator& operator=(BigNumberCalculator&& other) noexcept
    {
        // Move the other object's operations map to this object
        operations_ = std::move(other.operations_);
        // Clear the other object's operations map
        other.operations_.clear();
        return *this;
    }

	// output stream operator
    friend std::ostream& operator<<(std::ostream& out, const BigNumberCalculator& calculator)
    {
        // Print the result of the calculation as a string
        out << calculator.ToString();
        return out;
    }
};

#endif // !CISC187_MESA_BIG_NUMBER_CALCULATOR_H