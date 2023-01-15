#include "tree.h"

int main()
{
	std::ostringstream os;
	auto t = mesa::make_tree(1);
	auto u = mesa::make_tree(2);
	auto v = mesa::make_tree(3, t, u);
	os << v << '\n';
	mesa::post_order(os, v);
	os << v << '\n';
	mesa::in_order(os, v);
	os << v << '\n';
	mesa::level_order(os, v);
	os << v << '\n';
		
	std::cout << os.str();
}