#ifndef CISC187_MESA_LAB8_H
#define CISC187_MESA_LAB8_H
#include <numbers>
#include <cmath>
#include <math.h>

namespace mesa
{
	const double PI = std::atan(1.0) * 4;

	template <class T>
	constexpr double area(const T radius)
	{
		if (radius <= 0)
		{
			return 0;
		}

		const double area = radius * radius * PI;
		return (area);
	}

	template <class T>
	double perimeter(const T length, int16_t num_sides)
	{
		if (num_sides <= 2 || length <= 0)
		{
			return 0;
		}
		return length * num_sides;
	}

	template <class T, int16_t num_sides>
	double apothem(const T length)
	{
		if (length > 0 && num_sides > 2)
		{
			auto numSides = num_sides;

			auto tanInside = PI / numSides;

			auto preCalculation = tan(tanInside);

			auto calculation = (2.0 * preCalculation);

			auto apo = (length / calculation);

			return double(apo);
		}

		return 0;
	}

	template <class T, int16_t num_sides>
	auto area(const T length) -> decltype(length * 1.0f)
	{
		double apo = mesa::apothem<T, num_sides>(length);
		double perim = mesa::perimeter(length, num_sides);

		float area = (float(apo) * float(perim)) / (2.0f);

		return float(area);
	}
}

#endif // !CISC187_MESA_LAB8_H