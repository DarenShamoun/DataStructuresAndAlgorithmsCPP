#ifndef CISC187_MESA_ARRAY_H
#define CISC187_MESA_ARRAY_H

#include <initializer_list>
#include <algorithm>


namespace mesa
{
	template<class T, size_t N>
	class array
	{
	private:
		T data_[N];

	public:
		typedef T value_type;

		//default constructor
		array()
		{
			for (size_t i = 0; i < N; i++)
			{
				data_[i] = T{};
			}
		};

		//default destructor
		~array() = default;

		//allows the array to be initialized in an initializer list
		explicit array(const std::initializer_list<T>& list)
		{
			std::copy(list.begin(), list.end(), static_cast<T*>(data_));
		}

		//returns the size of the array
		constexpr
			size_t size() const noexcept { return N; }

		//returns a pointer to the underlying backing store.
		T* begin() { return data_; }

		//returns a const pointer to the underlying backing store.
		constexpr
			const T* begin() const noexcept { return data_; }

		//returns a pointer to the last element in the underlying backing store.
		T* end() { return data_ + N; }

		//returns a const pointer to the last element in the underlying backing store.
		constexpr
			const T* end() const noexcept { return data_ + N; }

		//checks if the array is empty
		constexpr
			bool empty() const noexcept
		{
			return begin() == end();
		}
	};
}
#endif // !CISC187_MESA_ARRAY_H
