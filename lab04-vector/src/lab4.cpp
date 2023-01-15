#include <iostream>
#include <string>
#include <vector>
#include "lab4.h"

std::vector<int> make_vector(int argc, const char* argv[])
{
	std::vector<int> result;

	if (argc == 0)
	{
		return result;
	}
 
	for (int i = 0; i < argc; i++)
	{
		result.push_back(int(atoi(argv[i])));
	}

	return result;
}

int add(int argc, const char* argv[]) 
{
	std::vector<int> newVector;
	
	if (argc == 0)
	{
		return 0;
	}

	newVector = make_vector(argc, argv);
	int sumOfVectorElements = 0;

	for (int i = 0; i < argc; i++)
	{
		sumOfVectorElements += newVector[i];
	}
	return sumOfVectorElements;
}

double mean(int argc, const char* argv[])
{
	std::vector<int> newVector = make_vector(argc, argv);

	if (newVector.size() > 1)
	{
		double sum = double(add(argc, argv));

		std::cout << sum << std::endl;

		double mean = (sum / double(newVector.size()));

		return mean;
	}
	if (newVector.size() == 1)
	{
		double singleValue = newVector[0];
		return singleValue;
	}
	return 0;
}

std::vector<int> odd(std::vector<int> temp)
{
	std::vector<int> oddVector;

	if (temp.size() != 0)
	{
		for (int i: temp)
		{
			if (i % 2 != 0)
			{
				oddVector.push_back(i);
			}
		}
		return oddVector;
	}

	return oddVector;
}

std::vector<int> reverse(std::vector<int> temp)
{
	std::vector<int> reversedVector;

	if(temp.size() != 0)
	{
		for (int i = int(temp.size() - 1); i >= 0; i--)
		{
			reversedVector.push_back(temp[i]);
		}
		return reversedVector;
	}
	
	return reversedVector;

}

