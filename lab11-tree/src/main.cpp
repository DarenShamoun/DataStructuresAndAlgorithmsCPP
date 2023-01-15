#include "tree.h"

int main()
{
	std::ostringstream os;
	auto t = mesa::make_tree(1);
	auto u = mesa::make_tree(2);
	auto v = mesa::make_tree(3,t,u);
	os << v;
	std::cout << os.str();
}