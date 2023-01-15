#ifndef CISC187_MESA_STACK_H
#define CISC187_MESA_STACK_H

#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include "bag.h"

namespace mesa
{
	template< class T, class Container = mesa::bag<T>>
	class stack
	{
	private:
		Container container_;
	public:
		typedef Container container_type;
		typedef typename container_type::value_type value_type;
		static_assert((std::is_same<T, value_type>::value),
			"stack type must match underlying container value type");
		
		//stack contructors
		stack()
			:
			container_()
		{}
		
		stack(const stack<T>& other)
			:
			container_(other.container_)
		{}
		
		stack(const container_type& other)
			:
			container_(other)
		{}
		
		stack<T>& operator=(const stack<T>& other)
		{
			container_ = other.container_;
			return *this;
		}
		
		stack(stack<T>&& other)
			:
			container_(std::move(other.container_))
		{}
		
		stack<T>& operator=(stack<T>&& other)
		{
			container_ = std::move(other.container_);
			return *this;
		}
		
		constexpr bool empty()   const noexcept
		{
			return container_.empty();
		}
		
		constexpr size_t size()  const noexcept
		{
			return container_.size();
		}
		
		T& top() 
		{
			return container_.back();
		}
		
		constexpr const T& top() const noexcept
		{
			return container_.back();
		}

		void push(const T& value)
		{
			container_.push_back(value);
		}
		
		void push(T&& value)
		{
			container_.push_back(std::move(value));
		}
		
		void pop()
		{
			container_.pop_back();
		}
		
		template <class T1, class C1>
		friend
			bool
			operator==(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

		template <class T1, class C1>
		friend
			bool
			operator< (const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
	};
	
	template <class T1, class C1>
	bool
		operator==(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs)
	{
		return lhs.container_ == rhs.container_;
	}
	
	template <class T1, class C1>
	bool
		operator< (const stack<T1, C1>& lhs, const stack<T1, C1>& rhs)
	{
		return lhs.container_ < rhs.container_;
	}

	template <class T1, class C1>
	bool
		operator!=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs)
	{
		return !(lhs == rhs);
	}
	
	template <class T1, class C1>
	bool
		operator> (const stack<T1, C1>& lhs, const stack<T1, C1>& rhs)
	{
		return rhs < lhs;
	}
	
	template <class T1, class C1>
	bool
		operator<=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs)
	{
		return !(rhs < lhs);
	}
	
	template <class T1, class C1>
	bool
		operator>=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif // !CISC187_MESA_STACK_H