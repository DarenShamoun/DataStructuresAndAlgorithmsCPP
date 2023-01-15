#ifndef CISC187_MESA_RING_BUFFER_H
#define CISC187_MESA_RING_BUFFER_H

#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include <array>

namespace mesa
{
	template<class T, size_t N>
	class ring_buffer
	{
	private:
		std::array <T, N> data_{}; // backing store array
		size_t head = 0;
		size_t size = 0;
		
	public:
		//constructor
		ring_buffer() = default;
		
		//destructor
		~ring_buffer() = default;
		
		T pop()
		{
			if (size == 0) //if it is empty
			{
				throw std::domain_error("The buffer is empty");
			}
			T& temp = data_[head];
			head = (head + 1) % N;
			--size;

			return temp;
		}
		
		void push(const T& value)
		{
			if (size == N) //if it is full
			{
				throw std::domain_error("The buffer is full");
			}
			data_[(head + size) % N] = value;
			++size;
		}

		void clear()
		{
			head = 0;
			size = 0;
		}

		void overwrite(const T& value)
		{
			if (size != N)
			{
				push(value);
			}
			else
			{
				data_[head] = value;
				head = (head + 1) % N;
			}
		}
	};
}

#endif // !CISC187_MESA_RING_BUFFER_H
