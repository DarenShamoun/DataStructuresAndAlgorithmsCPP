#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include <doctest.h>
#include "../src/options.h"

//
// For these tests to compile,
// a function wignature
// std::string help (const char*);
// needs to exist.
//

TEST_CASE( "a function help exists") {
  auto prog = "test_step_4";
  auto actual = help(prog);
  auto use = usage(prog);

  CHECK_MESSAGE(actual.substr(0,25) == use.substr(0,25), "the help should begin with the usage statement");
  CHECK_MESSAGE (actual.size() - use.size() > 25, "expected a useage statement plus meaningful help");
}


