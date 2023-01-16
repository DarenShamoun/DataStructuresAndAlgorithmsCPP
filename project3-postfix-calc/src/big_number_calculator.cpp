//Daren Shamoun
//ID# 5550016094
#include "big_number_calculator.h"

//creates a operation object and registers the operations
std::unique_ptr<Operation> static CreateOperation(const std::string& token)
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

//converts a string to a vector of ints
std::vector<int> static ToBigNumber(const std::string& number)
{
    std::vector<int> big_number;
    for (const char& digit : number)
    {
        big_number.push_back(digit - '0');
    }
    return big_number;
}

// Helper function to create a deep copy of an `Operation` object
std::unique_ptr<Operation> static CloneOperation(const std::unique_ptr<Operation>& operation)
{
    return std::unique_ptr<Operation>(operation->Clone());
}