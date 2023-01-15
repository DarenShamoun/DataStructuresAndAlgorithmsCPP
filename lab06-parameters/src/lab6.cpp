#include <iostream>
#include <string>
#include <cmath>
#include "lab6.h"

mesa::trigon mesa::make_triple(const int16_t m, const int16_t n)
{
	if (m > n && n > 0)
	{
		const float a = powf(m, 2) - powf(n, 2);
		const float b = 2.0f * static_cast<float>(m) * float(n);
		const float c = powf(m, 2) + powf(n, 2);
		return mesa::trigon { a ,b ,c };
	}
	if (m < n || n < 1)
	{
		return mesa::trigon { 0.0f ,0.0f ,0.0f };
	}
	return mesa::trigon{};
}

void mesa::scale(trigon& shape, const float scaleFactor)
{
	if (scaleFactor >= 0.01f)
	{
		shape.a *= scaleFactor;
		shape.b *= scaleFactor;
		shape.c *= scaleFactor;
	}
}

float mesa::area(const trigon& shape)
{
	if (shape.a > 0 && shape.b > 0 && shape.c > 0)
	{
		const float semiPerimiter = ((shape.a + shape.b + shape.c) / 2.0f);
		const float area = sqrtf((semiPerimiter) * (semiPerimiter - shape.a) * (semiPerimiter - shape.b) * (semiPerimiter - shape.c));
		return area;
	}
	return 0;
}

mesa::trigon mesa::smallest(const std::vector<mesa::trigon>& tempVector)
{
	std::vector<mesa::trigon> vectorHoldingTrigons = tempVector;
	const int vectorSize = static_cast<int> (vectorHoldingTrigons.size());
	std::vector<float> vectorHoldingAreas(vectorSize);

	if (vectorHoldingTrigons.size() == 0)
	{
		trigon vectorHoldingTrigons = { 0,0,0 };
		return vectorHoldingTrigons;
	}

	for (int i = 0; i < vectorSize; i++)
	{
		vectorHoldingAreas.at(i) = (area(vectorHoldingTrigons.at(i)));
	}

	int currentLowestIndex = 0;

	for (int i = 0; i < vectorSize; i++)
	{
		static auto indexOfSmallestArea = i;

		if (vectorHoldingAreas.at(i) <= vectorHoldingAreas.at(indexOfSmallestArea))
		{
			currentLowestIndex = i;
		}
	}
	return vectorHoldingTrigons.at(currentLowestIndex);
}


//mesa::trigon mesa::smallest(const std::vector<mesa::trigon>& tempVector)
//{
//	std::vector<mesa::trigon> vectorHoldingTrigons = tempVector;
//	const auto vectorSize = tempVector.size();
//	std::vector<float> vectorHoldingAreas(vectorSize);
//
//	if (vectorSize == 0)
//	{
//		trigon vectorHoldingTrigons = { 0,0,0 };
//		return vectorHoldingTrigons;
//	}
//
//	for (int i = 0 ; i < vectorSize; i++)
//	{
//		vectorHoldingAreas.push_back(area(vectorHoldingTrigons.at(i)));
//	}
//
//	int currentLowestIndex = 0;
//
//	for (auto i = 0; i < vectorSize; i++)
//	{
//		static auto indexOfSmallestArea = i;
//
//		if (vectorHoldingAreas[i] <= vectorHoldingAreas[indexOfSmallestArea])
//		{
//			currentLowestIndex = i;
//		}
//	}
//	return vectorHoldingTrigons.at(currentLowestIndex);
//}