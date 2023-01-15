#ifndef CISC187_MESA_ARRAY_H
#define CISC187_MESA_ARRAY_H

#include <initializer_list>
#include <algorithm>
#include <stdexcept>


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
			size_t size() const noexcept {return N;}

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

		//allows access to elements of the array with and index 
		T& operator[](const size_t index)
		{
			return data_[index];
		}

		//allows access to elements of the array with and index but returns a const address
		constexpr 
			const T& operator[](size_t index) const
		{
			return data_[index];
		}
		
		//allows access to elements of the array with and index 
		T& at(const size_t& index)
		{
			if (index > size())
			{
				throw std::out_of_range("Bad Index");
			}
			return data_[index];
		}

		//allows access to elements of the array with and index but returns a const address
		constexpr 
			const T& at(const size_t& index) const 
		{
			if (index > size())
			{
				throw std::out_of_range("Bad Index");
			}
			return data_[index];
		}

		//returns a pointer to the data store
		T* data()
		{
			return data_;
		}
		
		//returns a const pointer to the data store
		constexpr const T* data() const
		{
			return data_;
		}

		//returns the address of the last element in the array
		T& back()
		{
			return data_[N - 1];
		}
		
		//returns a const address of the last element in the array
		constexpr const T& back() const
		{
			return data_[N - 1];
		}
	};

	//all operator overloads
	template<class T, size_t N>
	bool operator==(const mesa::array<T, N>& lhs, const mesa::array<T, N>& rhs)
	{
		return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T, size_t N>
	bool operator!=(const mesa::array<T, N>& lhs, const mesa::array<T, N>& rhs)
	{
		return !(lhs == rhs);
	}

	template<class T, size_t N>
	bool operator<(const mesa::array<T, N>& lhs, const mesa::array<T, N>& rhs)
	{
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T, size_t N>
	bool operator>(const mesa::array<T, N>& lhs, const mesa::array<T, N>& rhs)
	{
		return rhs < lhs;
	}
	
	template<class T, size_t N>
	bool operator<=(const mesa::array<T, N>& lhs, const mesa::array<T, N>& rhs)
	{
		return !(rhs < lhs);
	}
	
	template<class T, size_t N>
	bool operator>=(const mesa::array<T, N>& lhs, const mesa::array<T, N>& rhs)
	{
		return !(lhs < rhs);
	}
}
#endif // !CISC187_MESA_ARRAY_H
