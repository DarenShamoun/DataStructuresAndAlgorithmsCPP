#ifndef CISC187_MESA_BAG_H
#define CISC187_MESA_BAG_H

#include <initializer_list>
#include <algorithm>
#include <stdexcept>


namespace mesa
{
	template<class T>
	class bag
	{
	private:
		T* data_ = nullptr;
		size_t capacity_ = 0;
		size_t size_ = 0;

	public:
		using value_type = T;

		//default constructor
		bag() = default;

		//single arguement constructor
		explicit bag(size_t size)
			:
			capacity_(size), size_(size), data_(new T[size])
		{
			for (size_t i = 0; i < size_; i++)
			{
				data_[i] = T{};
			}
		}

		//construct a bag out of another bag object
		bag(const bag<T>& other)
			:
			capacity_(other.capacity_), size_(other.size_), data_(new T[other.capacity_])
		{
			std::copy(other.begin(), other.end(), begin());
		}

		//allows the array to be initialized in an initializer list
		explicit bag(const std::initializer_list<T>& list)
			:
			size_(list.size()), capacity_(list.size()), data_(new T[list.size()])
		{
			std::copy(list.begin(), list.end(), static_cast<T*>(data_));
		}

		//destructor
		~bag()
		{
			delete[] data_;
		}

		//returns the size of the array
		constexpr
			size_t size() const noexcept { return size_; }

		//returns the capacity of the array
		constexpr
			size_t capacity() const noexcept { return capacity_; }

		//adds extra capcity to the array
		void reserve(size_t new_capacity)
		{
			if (new_capacity > capacity_)
			{
				T* temp = new T[new_capacity];
				std::copy(begin(), end(), temp);
				delete[] data_;
				data_ = temp;
				capacity_ = new_capacity;
			}
		}

		//resizes the array and initializes the new elements
		void resize(size_t new_capacity)
		{
			if (new_capacity > capacity_)
			{
				reserve(new_capacity);
				for (size_t i = size_; i < new_capacity; i++)
				{
					data_[i] = T{};
				}
				size_ = new_capacity;
			}
			else
			{
				size_ = new_capacity;
			}
		}

		//adds one element to the bag
		void push_back(T value)
		{
			if (size_ == capacity_)
			{
				if (capacity_ == 0)
				{
					reserve(1);
				}
				else
				{
					reserve(capacity_ * 2);
				}
			}
			data_[size_] = value;
			size_++;
		}

		//removes an element from the bag
		void pop_back()
		{
			if (size_ > 0)
			{
				--size_;
			}
		}

		//returns a pointer to the underlying backing store.
		T* begin() { return data_; }

		//returns a const pointer to the underlying backing store.
		constexpr
			const T* begin() const noexcept { return data_; }

		//returns a pointer to the last element in the underlying backing store.
		T* end() { return data_ + size_; }

		//returns a const pointer to the last element in the underlying backing store.
		constexpr
			const T* end() const noexcept { return data_ + size_; }

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
			return data_[size_ - 1];
		}

		//returns a const address of the last element in the array
		constexpr const T& back() const
		{
			return data_[size_ - 1];
		}

		//copy assignment overload
		bag<T>& operator=(const bag<T>& other)
		{
			if (this != &other)
			{
				delete[] data_;
				size_ = other.size_;
				capacity_ = other.capacity_;
				data_ = new T[capacity_];
				std::copy(other.begin(), other.end(), begin());
			}
			return *this;
		}
	};

	//all operator overloads
	template<class T>
	bool operator==(const mesa::bag<T>& lhs, const mesa::bag<T>& rhs)
	{
		return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T>
	bool operator!=(const mesa::bag<T>& lhs, const mesa::bag<T>& rhs)
	{
		return !(lhs == rhs);
	}

	template<class T>
	bool operator<(const mesa::bag<T>& lhs, const mesa::bag<T>& rhs)
	{
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T>
	bool operator>(const mesa::bag<T>& lhs, const mesa::bag<T>& rhs)
	{
		return rhs < lhs;
	}

	template<class T>
	bool operator<=(const mesa::bag<T>& lhs, const mesa::bag<T>& rhs)
	{
		return !(rhs < lhs);
	}

	template<class T>
	bool operator>=(const mesa::bag<T>& lhs, const mesa::bag<T>& rhs)
	{
		return !(lhs < rhs);
	}
}
#endif // !CISC187_MESA_BAG_H
