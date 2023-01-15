#include "array.h"

#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <stdexcept>

int main()
{
	mesa::array<int, 5> test_array1;
	auto test_array2 = mesa::array<int, 5> { 1, 2, 3, 4, 5 };
	auto test_array3 = mesa::array<int, 5> { 5, 4, 3, 2, 1 };

	size_t size1 = test_array1.size();
	size_t size2 = test_array2.size();
	size_t size3 = test_array3.size();

	int* begin1 = test_array1.begin();
	int* begin2 = test_array2.begin();
	int* begin3 = test_array3.begin();
	
	int* end1 = test_array1.end();
	int* end2 = test_array2.end();
	int* end3 = test_array3.end();

	bool empty1 = test_array1.empty();
	bool empty2 = test_array2.empty();
	bool empty3 = test_array3.empty();
	
	const int* constBegin1 = test_array1.begin();
	const int* constBegin2 = test_array2.begin();
	const int* constBegin3 = test_array3.begin();

	const int* constEnd1 = test_array1.end();
	const int* constEnd2 = test_array2.end();
	const int* constEnd3 = test_array3.end();
	
	int data2 = test_array2[0];
	int data3 = test_array3[0];
	
	int data2_2 = test_array2.at(0);
	int data3_2 = test_array3.at(0);
	
	const int constData2 = test_array2[0];
	const int constData3 = test_array3[0];

	const int constData2_2 = test_array2.at(0);
	const int constData3_2 = test_array3.at(0);
	
	int* dataPtr1 = test_array1.data();
	int* dataPtr2 = test_array2.data();
	int* dataPtr3 = test_array3.data();
	
	const int* constDataPtr1 = test_array1.data();
	const int* constDataPtr2 = test_array2.data();
	const int* constDataPtr3 = test_array3.data();
	
	int back1 = test_array1.back();
	int back2 = test_array2.back();
	int back3 = test_array3.back();
	
	const int constBack1 = test_array1.back();
	const int constBack2 = test_array2.back();
	const int constBack3 = test_array3.back();
	
	
	std::cout << size1 << ' ' << begin1 << ' ' << end1 << ' ' << constBegin1
		<< ' ' << constEnd1 << ' ' << empty1 << std::endl;

	std::cout << size2 << ' ' << begin2 << ' ' << end2 << ' ' << constBegin2
		<< ' ' << constEnd2 << ' ' << empty2 << std::endl;
	
	return 0;
}