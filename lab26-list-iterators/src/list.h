#ifndef CISC187_MESA_LIST_H
#define CISC187_MESA_LIST_H

#include <iostream>
#include <memory>
#include <iterator>
#include <cstddef>


namespace mesa
{
    template <class T>
    struct list_node 
    {
        T value;
        list_node* next;
        explicit list_node(const T& v, list_node* next = nullptr)
            : value{ v }
            , next{ next }
        { }
    };

    template <typename T>
    struct list_iterator 
    {
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

		list_node<T>* node = nullptr;
        
		list_iterator() = default;
        
		list_iterator(list_node<T>* n) 
            : node{ n } 
        { }
        
        T& operator*() const
        {
            return node->value;
        }

        // overload for prefix increment
        list_iterator& operator++()
        {
            if (node != nullptr)
            {
                node = node->next;
            }
            return *this;
        }

        // overload for postfix increment
        list_iterator operator++(int)
        {
            list_iterator temp = *this;
            ++(*this);
            return temp;
        }

        // overload for the equality operator
        friend bool operator==(const list_iterator& lhs, const list_iterator& rhs)
        {
            return lhs.node == rhs.node;
        }

        // overload for the inequality operator
        friend bool operator!=(const list_iterator& lhs, const list_iterator& rhs)
        {
            return !(lhs == rhs);
        }
        
	};

    
    
	template <class T>
    class list
    {
    private:
        list_node<T>* head = nullptr;
        size_t count = 0;

    public:
		typedef T value_type;
        using iterator = list_iterator<T>;

        list() = default;
        
		list(T value)
            : head{ new list_node<T>(value) }
            , count {1}
		{}
        
		~list()
		{
			while (head != nullptr)
			{
				pop_front();
			}
		}
        
        list(const list&) = delete;
        list(list&&) = delete;

        list& operator=(const list<T>&) = delete;
        list& operator=(list<T>&&) = delete;
        
        void push_front(const T& value)
        {
			list_node<T>* new_node = new list_node<T>(value);
			new_node->next = head;
			head = new_node;
            count++;
        }

        constexpr const T& front() const
        {
			return head->value;
        }

        T& front()
        {
            return head->value;
        }
        
        constexpr size_t size() const noexcept
        {
			return count;
        }
        
        constexpr bool empty() const noexcept
        {
            return count == 0;
        }
        
        void pop_front()
        {
            if (head != nullptr)
            {
				auto temp = head;
				head = head->next;
				delete temp;
				count--;
            }
        }

        iterator insert_after(iterator it, const T& value)
        {
            auto temp = it.node;

            if (temp == nullptr)
                return end();

            auto new_node = new list_node<T>(value);
            new_node->value = value;

            new_node->next = temp->next;
            temp->next = new_node;

            count++;
            return iterator{ new_node };
        }

        iterator erase_after(iterator it)
        {
            auto temp = it.node;

            if (temp == nullptr || temp->next == nullptr)
                return end();

            auto next_node = temp->next;
            temp->next = next_node->next;
            delete next_node;
            count--;
            return iterator{ temp->next };
        }
        
        constexpr iterator begin() noexcept
        {
            return iterator{ head };
        }

        iterator end() noexcept
        {
            return iterator{ nullptr };
        }

        constexpr iterator begin() const noexcept
        {
            return iterator{ head };
        }

        const iterator end() const noexcept
        {
            return iterator{ nullptr };
        }
    };
}
#endif // !CISC187_MESA_LIST_H
