#include "bag.h"
#include <iostream>

void printBagStats(mesa::bag<int> a, mesa::bag<int> b);

int main ()
{
	//initializing test objects and printing their data
	mesa::bag<int> b1{ 1, 2, 3, 4, 5 };
	mesa::bag<int> copyOfb1 = b1;
	
	printBagStats(b1, copyOfb1);
	
	//testing the reserve function
	std::cout << "Testing reserve function" << std::endl;
	
	b1.reserve(10);
	copyOfb1.reserve(7);
	
	printBagStats(b1, copyOfb1);
	
	//testing the resize function
	std::cout << "Testing resize function" << std::endl;
	
	b1.resize(10);
	copyOfb1.resize(7);
	
	printBagStats(b1, copyOfb1);
	
	//testing the push_back function
	std::cout << "Testing push_back function" << std::endl;
	
	b1.push_back(6);
	copyOfb1.push_back(7);
	
	printBagStats(b1, copyOfb1);
	
	//testing the pop_back function
	std::cout << "Testing pop_back function" << std::endl;
	
	b1.pop_back();
	copyOfb1.pop_back();
	
	printBagStats(b1, copyOfb1);
	
  return 0;
}

void printBagStats(mesa::bag<int> a, mesa::bag<int> b)
{
	std::cout << "size of original: " << a.size() << std::endl;
	std::cout << "size of copy: " << b.size() << std::endl;

	std::cout << "capacity of original: " << a.capacity() << std::endl;
	std::cout << "capacity of copy: " << b.capacity() << std::endl;

	std::cout << "address of original: " << a.data() << std::endl;
	std::cout << "address of copy: " << b.data() << std::endl << std::endl;
}
