#ifndef CISC187_MESA_LAB9_H
#define CISC187_MESA_LAB9_H
#include <cstdlib>


namespace mesa
{
	void to_lower(char*);

	char* copy(const char* source, const std::size_t count);

	size_t count(const char*, const char);

	template<class Pointer>
	Pointer min(Pointer begin, Pointer end)
	{
		if (begin == end)
		{
			return end;
		}

		Pointer lowestAddress = begin;
		auto lowestValue = *begin;

		while (begin != end)
		{
			if (lowestValue > *begin)
			{
				lowestAddress = begin;
				lowestValue = *begin;
			}
			begin++;
		}
		return lowestAddress;
	}
}
#endif // !CISC187_MESA_LAB9_H