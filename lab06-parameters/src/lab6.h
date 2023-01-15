#ifndef CISC187_MESA_LAB6_H
#define CISC187_MESA_LAB6_H
#include <cstdint>
#include <vector>

namespace mesa
{
	struct trigon 
	{
		float a;
		float b;
		float c;
	};

	trigon make_triple(const int16_t m, const int16_t n);

	void  scale(trigon& shape, const float);

	float area(const trigon& shape);

	trigon smallest(const std::vector<trigon>&);
}
#endif // !CISC187_MESA_LAB6_H
