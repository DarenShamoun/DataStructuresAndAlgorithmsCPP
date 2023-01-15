#include "lab9.h"


void mesa::to_lower(char* charArray)
{
	for (int i = 0; charArray[i] != '\0'; i++)
	{
		if (charArray[i] >= 'A' && charArray[i] <= 'Z')
		{
			charArray[i] += 32;
		}
	}
}

char* mesa::copy(const char* source, const size_t count)
{
	const int numberOfItems = count;
	char* copy = new (char[count + 1]);

	for (int i = 0; source[i] != '\0'; i++)
	{
		copy[i] = source[i];
	}

	return copy;
}

size_t mesa::count(const char* source, const char val)
{
	size_t res = 0;

	for (int i = 0; source[i] != '\0'; i++)
	{
		if (source[i] == val)
			res++;
	}

	return res;
}

