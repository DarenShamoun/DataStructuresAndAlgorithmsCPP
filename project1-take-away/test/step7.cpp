#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <string>
#include <sstream>
#include <doctest.h>
#include "../src/game.h"

//
// For these tests to compile,
// a function signature
// uint32_t get_value (const std::string prompt);
// needs to exist.
//

TEST_CASE( "get an int from the user") {
  auto in_buf = std::cin.rdbuf();
  auto out_buf = std::cout.rdbuf();
  std::ostringstream out;
  std::cout.rdbuf(out.rdbuf());
  std::istringstream input ("3");
  std::cin.rdbuf(input.rdbuf());
  auto actual = get_value("which heap? ");
  auto expected = input.str();

  std::cout.rdbuf(out_buf);
  std::cin.rdbuf(in_buf);
  CHECK (expected == std::to_string(actual));
}


