#ifndef CISC187_MESA_LAB7_H
#define CISC187_MESA_LAB7_H

namespace mesa
{
	template <class T>
	auto constexpr abs(T value)
	{
		return value < 0 ? -value : value;
	}

	struct point 
	{
		int x;
		int y;
	};

	inline
		bool operator==(const mesa::point& lhs, const mesa::point& rhs)
	{
		return (lhs.x == rhs.x && lhs.y == rhs.y);
	}

	inline
		bool operator!=(const mesa::point& lhs, const mesa::point& rhs)
	{
		return !(lhs == rhs);
	}

	inline
		std::ostream& operator<<(std::ostream& os, const mesa::point& point)
	{
		return (os << '[' << point.x << ',' << point.y << ']');
	}
}

#endif // !CISC187_MESA_LAB7_H 