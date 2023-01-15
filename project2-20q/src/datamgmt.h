//Daren Shamoun
//ID# 5550016094
#ifndef CISC187_MESA_DATAMGMT_H
#define CISC187_MESA_DATAMGMT_H
#include "tree.h"
#include "options.h"
#include "twentyq.h"
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cstdlib>


namespace mesa
{
	std::string get_user_input();

	bool yes_no();

	mesa::tree<std::string>* read_data(std::ifstream& input);

	mesa::tree<std::string>* initialize_tree(mesa::option& userOptions, std::ifstream& input);
	
	void save_game(mesa::tree<std::string>* tree, std::ofstream& output);

	void delete_tree(mesa::tree<std::string>* tree);
}
#endif // !CISC187_MESA_DATAMGMT_H
