#include <vector>
#include <cmath>

#include "average.h"


double average (const std::vector<int>& grades) 
{
  // Your code here.
  // return the average of all the grades in the vector
	double sum = 0;
	double average = 0;
	if (!grades.empty())
	{
		for (auto i : grades)
		{
			sum += i;
		}
		average = sum / double(grades.size());
	}
	average = std::ceil(average * 100.0) / 100.0;
	return average;
}

