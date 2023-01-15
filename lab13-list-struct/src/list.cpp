#include "list.h"

std::ostream& operator<<(std::ostream& os, const list* l)
{
	if (l == nullptr)
	{
		os << "nullptr";
		return os;
	}
	os << l->val << ' ';
	if (l->next != nullptr)
	{
		os << l->next;
	}

	return os;
}

list* erase(list* l)
{
	if (l == nullptr)
	{
		return nullptr;
	}
	list* temp = l->next;
	delete l;
	return temp;
}