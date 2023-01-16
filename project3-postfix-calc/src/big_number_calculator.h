//Daren Shamoun
//ID# 5550016094
#ifndef CISC187_MESA_BIG_NUMBER_CALCULATOR_H
#define CISC187_MESA_BIG_NUMBER_CALCULATOR_H

#include "operation.h"
#include "addition.cpp"
#include "subtraction.cpp"
#include "multiplication.cpp"
#include "division.cpp"
#include "exponentiation.cpp"

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

std::unique_ptr<Operation> static CreateOperation(const std::string& token);
std::vector<int> static ToBigNumber(const std::string& number);
std::unique_ptr<Operation> static CloneOperation(const std::unique_ptr<Operation>& operation);

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

    std::vector<int> static ParseBigNumber(const std::string& number)
    {
        std::vector<int> bigNumber;
        for (const char ch : number)
        {
            if (!bool(isdigit(ch)))
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
        std::vector<int> operands;
        std::stack<std::unique_ptr<Operation>> operations;

        std::stringstream ss(expression);
        std::string token;
        while (ss >> token)
        {
            if (IsOperator(token))
            {
                auto operation = CreateOperation(token);

                // Pop the required number of operands from the operands stack
                const size_t operandCount = operation->GetOperandCount();
                std::vector<int> operationOperands;
                operationOperands.reserve(operandCount);
                for (size_t i = 0; i < operandCount; i++)
                {
                    operationOperands.insert(operationOperands.end(), operands.end() - operandCount, operands.end());
                    operands.erase(operands.end() - operandCount, operands.end());
                }

                // Perform the operation and push the result onto the operands stack
                const std::vector<int> result = operation->handle(operationOperands);
                operands = std::move(result);

                // Push the operation onto the operations stack
                operations.push(std::move(operation));
            }
            else
            {
                // Parse the token as a big number and push it onto the operands stack
                operands.insert(operands.end(), ParseBigNumber(token).begin(), ParseBigNumber(token).end());
            }
        }

        // The result should be the only operand left on the stack
        if (operands.empty())
        {
            throw std::invalid_argument("Invalid expression");
        }
        m_result = std::move(operands);
    }
  
    static bool IsOperand(const std::string& token)
    {
        return std::all_of(token.begin(), token.end(), ::isdigit);
    }

    std::string ToString() const
    {
        std::stringstream ss;
        for (auto i = m_result.size() - 1; i >= 0; i--)
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
                auto operand_count = GetOperandCount(token);
                std::vector<std::vector<int>> operands;
                while (operand_count-- > 0)
                {
                    operands.push_back(operand_stack.top());
                    operand_stack.pop();
                }
                const std::vector<int> result = GetOperation(token)->handle(operands);
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