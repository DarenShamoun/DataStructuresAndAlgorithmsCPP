//Daren Shamoun
//ID# 5550016094
#include "big_number_calculator.h"
#include "options.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
	std::cout << "Welcome to the Big Number Calculator!\n";
	std::cout << "this calculator operates in postfix notation ex: 5 5 5 * * = 125 \n";
    std::cout << "Enter 'quit' to exit the program at any time.\n";
    
    //get user options from the command line
	auto playerOptions = mesa::get_options(argc, argv);
    
	//if the user has a filename specified read the file and process the expressions
	if (playerOptions.load)
    {
		//read the file and process the expressions
    }

    // Process input interactively
    BigNumberCalculator calculator;
    std::string line;
    while (playerOptions.again)
    {
        std::cout << "> ";
        std::getline(std::cin, line);
        if (line == "quit")
        {
			playerOptions.again = false;
            break;
        }
        else if (line.empty() || line[0] == '#')
        {
            continue;
        }
        else
        {
            // Calculate the result of the expression
            calculator.Calculate(line);

            // Output the result
            std::cout << line << " = " << calculator << std::endl;
        }
    }
    return 0;
}