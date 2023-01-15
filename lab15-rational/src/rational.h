#pragma once
#include <iostream>
#include <ostream>
#include <limits>

class rational
{
	int numer;
	int denom;
public:
	rational()
		: numer(0),
		denom(1)
	{}
	rational(int n)
		: numer(n),
		denom(1)
	{}
	rational(int n, int d)
		: numer(n),
		denom(d)
	{}


	int numerator() const
	{
		return this->numer;
	}
	int denominator() const
	{
		return this->denom;
	}

	double to_double() const
	{
		if (this->denom == 0)
		{
			return std::numeric_limits<double>::infinity();
		}
		return double(this->numer) / double(this->denom);
	}

	operator double() const
	{
		return double(this->numer) / double(this->denom);
	}
	
	operator std::string() const
	{
		if (this->numer == 0)
		{
			return "0";
		}
		if (this->denom == 0)
		{
			return "inf";
		}
		if (this->numer == this->denom)
		{
			return "1";
		}
		return std::to_string(this->numer) + "/" + std::to_string(this->denom);
	}
};

inline std::ostream& operator<<(std::ostream& os, const rational& r)
{
	os << std::string(r);
	return os;
}