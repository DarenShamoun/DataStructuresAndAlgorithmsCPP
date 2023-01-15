#ifndef CISC187_MESA_LAB4_H
#define CISC187_MESA_LAB4_H

#include <string>
#include <vector>

std::vector<int> make_vector(int argc, const char* argv[]);
int add(int argc, const char* argv[]);
double mean(int argc, const char* argv[]);
std::vector<int> odd(std::vector<int> temp);
std::vector<int> reverse(std::vector<int> temp);

#endif