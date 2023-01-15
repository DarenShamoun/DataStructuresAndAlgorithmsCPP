//Daren Shamoun
//ID# 5550016094
#ifndef CISC187_MESA_OPTIONS_H
#define CISC187_MESA_OPTIONS_H

#include <string>

namespace mesa
{
	struct option
	{
		bool valid = true;
		bool load = false;
		bool again = true;
		std::string filename = "data.txt";
	};
	
	mesa::option get_options(int argc, char** argv);

	std::string usage(const char* argv);
	
	std::string help(const char* argv);
}
#endif // !CISC187_MESA_OPTIONS_H