#ifndef CISC187_MESA_LAB11_H
#define CISC187_MESA_LAB11_H
#include <iostream>
#include <sstream>
#include <memory>
#include <queue>

namespace mesa
{
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

	template <class T>
	void post_order(std::ostream& os, const mesa::tree<T>* t)
	{
		if (t == nullptr)
		{
			return;
		}
		post_order(os,t->left);
		post_order(os,t->right);
		os << t->value << " ";
	}
	
	template <class T>
	void in_order(std::ostream& os, const mesa::tree<T>* t)
	{
		if (t == nullptr)
		{
			return;
		}
		in_order(os, t->left);
		os << t->value << " ";
		in_order(os, t->right);
	}
	
	template <class T>
	void level_order(std::ostream& os, mesa::tree<T>* t)
	{
		if (!t) return;
		
		std::queue<tree<T>*> q;
		q.push(t);
		while (!q.empty())
		{
			auto n = q.front();
			os << n->value << " ";
			q.pop();
			if (n->left) q.push(n->left);
			if (n->right) q.push(n->right);
		}
	}
}
#endif // !CISC187_MESA_LAB11_H