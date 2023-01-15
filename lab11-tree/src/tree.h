#ifndef CISC187_MESA_LAB11_H
#define CISC187_MESA_LAB11_H
#include <iostream>
#include <sstream>
#include <memory>

namespace mesa
{
    // a recursive binary tree
    template<class T>
    struct tree 
    {
        T value;
        tree<T>* left = nullptr;
        tree<T>* right = nullptr;
    };
	
	template<class T>
	tree<T>* make_tree(T value)
	{
		tree<T>* t = new tree<T>;
		t->value = value;
		return t;
	}
	
	template<class T>
	tree<T>* make_tree(T value, tree<T>* left, tree<T>* right)
	{
		tree<T>* t = new tree<T>;
		t->value = value;
		t->left = left;
		t->right = right;
		return t;
	}


	//Implement a function template overload for stream extraction
	template<class T>
	std::ostream& operator<<(std::ostream& os, const mesa::tree<T>* t)
	{
		if (t == nullptr)
		{
			return os;
		}
		os << t->value << " ";
		os << t->left;
		os << t->right;
		return os;
	}
}


#endif // !CISC187_MESA_LAB11_H