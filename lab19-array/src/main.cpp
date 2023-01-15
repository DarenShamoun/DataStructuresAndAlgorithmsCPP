#include "array.h"
#include <iostream>

int main ()
{
	mesa::array<int, 5> test_array;
	
	size_t size = test_array.size();
	
	int* begin = test_array.begin();
	int* end = test_array.end();
	
	const int* constBegin = test_array.begin();
	const int* constEnd = test_array.end();
	
	bool empty = test_array.empty();
	

	auto test_array2 = mesa::array<int, 5> { 1, 2, 3, 4, 5 };
	
	size_t size2 = test_array2.size();
	
	int* begin2 = test_array2.begin();
	int* end2 = test_array2.end();
	
	const int* constBegin2 = test_array2.begin();
	const int* constEnd2 = test_array2.end();
	
	bool empty2 = test_array2.empty();
	
	
	std::cout << size << ' ' << begin << ' ' << end << ' ' << constBegin 
		<< ' ' << constEnd << ' ' << empty << std::endl;
	
	std::cout << size2 << ' ' << begin2 << ' ' << end2 << ' ' << constBegin2
		<< ' ' << constEnd2 << ' ' << empty2 << std::endl;
	
  return 0;
}

