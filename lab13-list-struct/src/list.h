#ifndef CISC_MESA_LAB13_LIST_H
#define CISC_MESA_LAB13_LIST_H
#include <ostream>

struct list 
{
	int val = 0;
	list* next = nullptr;

	explicit list(const int value = 0)
	{
		this->val = value;
	}
	
	list* insert(int value)
	{
		list* node = new list{ value };
		node->next = this;
		return node;
	}
};

std::ostream& operator<<(std::ostream&, const list*);

list* erase(list*);

#endif // !CISC_MESA_LAB13_LIST_H