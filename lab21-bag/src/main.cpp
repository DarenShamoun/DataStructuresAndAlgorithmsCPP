#include "bag.h"
#include <iostream>

void print_bags(const mesa::bag<int>& b1, const mesa::bag<int>& b2,
	const mesa::bag<int>& b3, const mesa::bag<int>& b4);

int main ()
{
	mesa::bag<int> b1{ 1, 2, 3, 4, 5 };		//initializer list construct
	std::cout << "b1 is initializer list constructed" << std::endl;
	
	mesa::bag<int> b2(b1);		//construct from another bag
	std::cout << "b2 is copy constructed from b1" << std::endl;
	
	mesa::bag<int> b3(5);		//single arguement construct
	std::cout << "b3 is single arguement constructed" << std::endl;
	
	mesa::bag<int> b4;			//default construct
	std::cout << "b4 is default constructed" << std::endl << std::endl;
	
	print_bags(b1, b2, b3, b4);
	
  return 0;
}

void print_bags(const mesa::bag<int>& b1, const mesa::bag<int>& b2,
	const mesa::bag<int>& b3, const mesa::bag<int>& b4)
{
	std::cout << "size of b1: " << b1.size() << std::endl;
	std::cout << "size of b2: " << b2.size() << std::endl;
	std::cout << "size of b3: " << b3.size() << std::endl;
	std::cout << "size of b4: " << b4.size() << std::endl << std::endl;

	std::cout << "capacity of b1: " << b1.capacity() << std::endl;
	std::cout << "capacity of b2: " << b2.capacity() << std::endl;
	std::cout << "capacity of b3: " << b3.capacity() << std::endl;
	std::cout << "capacity of b4: " << b4.capacity() << std::endl << std::endl;

	std::cout << "Beggining address of b1: " << b1.begin() << std::endl;
	std::cout << "End address of b1: " << b1.end() << std::endl;
	std::cout << "Beggining address of b2: " << b2.begin() << std::endl;
	std::cout << "End address of b2: " << b2.end() << std::endl;
	std::cout << "Beggining address of b3: " << b3.begin() << std::endl;
	std::cout << "End address of b3: " << b3.end() << std::endl;
	std::cout << "Beggining address of b4: " << b4.begin() << std::endl;
	std::cout << "End address of b4: " << b4.end() << std::endl << std::endl;
}