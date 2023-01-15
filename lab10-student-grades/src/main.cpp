#include <iostream>
#include <sstream>
#include <fstream>

#include "average.h"
#include "student.h"

int main() 
{
  // Your code here. 
  // get a classroom from the load_classroom function
  // and print the classroom

	std::ifstream in("class.txt");
	std::cin.rdbuf(in.rdbuf());

	std::vector<student*> classroom = load_classroom();

	std::ostringstream os;
	os << classroom;

	std::cout << os.str();

  // Your code here.  Clean up all pointers on the heap

	for (auto student : classroom)
	{
		delete student;
	}
}

