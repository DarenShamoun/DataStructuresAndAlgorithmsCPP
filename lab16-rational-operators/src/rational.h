#pragma once
#include <iostream>
#include <ostream>
#include <limits>
#include <tuple>
#include <algorithm>
#include <string>

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
		return numer;
	}
	int denominator() const
	{
		return denom;
	}

	double to_double() const
	{
		if (denom == 0)
		{
			return std::numeric_limits<double>::infinity();
		}
		return double(numer) / double(denom);
	}

	explicit operator double() const
	{
		return double(numer) / double(denom);
	}
	
	operator std::string() const
	{
		if (numer == 0)
		{
			return "0";
		}
		if (denom == 0)
		{
			return "inf";
		}
		if (numer == denom)
		{
			return "1";
		}
		return std::to_string(numer) + "/" + std::to_string(denom);
	}

	inline rational& operator=(rational rhs) noexcept
	{
		if (*this == rhs)
		{
			return *this;
		}

		using std::swap;
		swap(*this, rhs);
		return *this;
	}

	inline rational& operator+=(const rational& rhs)
	{
		numer = numer * rhs.denom + rhs.numer * denom;
		denom = denom * rhs.denom;
		return *this;
	}

	inline rational& operator-=(const rational& rhs)
	{
		numer = (numer * rhs.denom) - (rhs.numer * denom);
		denom = denom * rhs.denom;
		return *this;
	}

	inline rational& operator*=(const rational& rhs)
	{
		numer = numer * rhs.numer;
		denom = denom * rhs.denom;
		return *this;
	}
	
	inline rational& operator/=(const rational& rhs)
	{
		if (numer == 0 || rhs.numer == 0)
		{
			numer = 0;
			denom = 0;
			return *this;
		}
		numer = numer * rhs.denom;
		denom = denom * rhs.numer;
		return *this;
	}

	friend void swap(rational& lhs, rational& rhs) noexcept;
	friend inline bool operator<(const rational& lhs, const rational& rhs);
	friend inline bool operator==(const rational& lhs, const rational& rhs);
};

inline bool operator<(const rational& lhs, const rational& rhs)
{
	return ((lhs.numer * rhs.denom) < (rhs.numer * lhs.denom));
}

inline bool operator==(const rational& lhs, const rational& rhs)
{
	return ((lhs.numer * rhs.denom) == (rhs.numer * lhs.denom));
}

inline void swap(rational& lhs, rational& rhs) noexcept
{
	using std::swap;
	std::swap(lhs.numer, rhs.numer);
	std::swap(lhs.denom, rhs.denom);
}

inline std::ostream& operator<<(std::ostream& os, const rational& r)
{
	os << std::string(r);
	return os;
}

inline bool operator>(const rational& lhs, const rational& rhs) {return rhs < lhs;}

inline bool operator<=(const rational& lhs, const rational& rhs) {return !(lhs > rhs);}

inline bool operator>=(const rational& lhs, const rational& rhs) {return !(lhs < rhs);}

inline bool operator!=(const rational& lhs, const rational& rhs) {return !(lhs == rhs);}


inline rational operator+(rational lhs, const rational rhs)
{
	lhs += rhs;
	return lhs;
}

inline rational operator-(rational lhs, const rational rhs)
{
	lhs -= rhs;
	return lhs;
}

inline rational operator*(rational lhs, const rational rhs)
{
	lhs *= rhs;
	return lhs;
}

inline rational operator/(rational lhs, const rational rhs)
{
	lhs /= rhs;
	return lhs;
}