#ifndef CISC187_MESA_LIST_H
#define CISC187_MESA_LIST_H

#include <iostream>
#include <memory>


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
    
	template <class T>
    class list
    {
    private:
        list_node<T>* head = nullptr;
        size_t count = 0;

    public:
		typedef T value_type;

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

        void insert_after(const int pos, const T& value)
        {
            auto temp = head;
            int num = 0;

            while (temp != nullptr && num < pos)
            {
                temp = temp->next;
                num++;
            }

            if (temp == nullptr)
                return;

            auto new_node = new list_node<T>(value);;
            new_node->value = value;

            new_node->next = temp->next;
            temp->next = new_node;

            count++;
        }
    };
}
#endif // !CISC187_MESA_LIST_H
