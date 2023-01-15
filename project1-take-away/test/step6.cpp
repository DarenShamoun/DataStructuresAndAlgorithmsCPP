#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <string>
#include <sstream>
#include <doctest.h>
#include "../src/game.h"

//
// For these tests to compile,
// a function signature
// std::string get_entry (const std::string prompt);
// needs to exist.
//

TEST_CASE( "get a name from the user") {
  auto in_buf = std::cin.rdbuf();
  auto out_buf = std::cout.rdbuf();
  std::ostringstream out;
  std::cout.rdbuf(out.rdbuf());
  std::istringstream input ("Dudley");
  std::cin.rdbuf(input.rdbuf());
  auto actual = get_entry("player 1 name: ");
  auto expected = input.str();

  std::cout.rdbuf(out_buf);
  std::cin.rdbuf(in_buf);
  CHECK (expected == actual);
}


TEST_CASE( "if the user enter nothing, prompt the user again") {
  auto in_buf = std::cin.rdbuf();
  auto out_buf = std::cout.rdbuf();
  std::ostringstream out;
  std::cout.rdbuf(out.rdbuf());
  std::istringstream input ("\n");
  std::cin.rdbuf(input.rdbuf());
  auto actual = get_entry("player 1 name: ");
  auto expected = out.str();

  std::cout.rdbuf(out_buf);
  std::cin.rdbuf(in_buf);
  CHECK ("" == actual);
  CHECK_MESSAGE (expected == "player 1 name: ", "did not prompt again");
}


