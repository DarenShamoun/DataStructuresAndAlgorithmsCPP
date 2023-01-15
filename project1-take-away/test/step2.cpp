#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/options.h"

using mesa::option;

//
// For these tests to compile,
// the struct mesa::option
// needs to exist with the following members:
// - bool valid
// - bool has_ai
// uint32_t piles
// uint32_t stones
//

TEST_CASE( "Test struct mesa::option exists") {
  option opt;
  CHECK_MESSAGE (opt.valid == true, "the default value for valid should be true");
  CHECK_MESSAGE (opt.has_ai == false, "the default value for has_ai should be false");
  CHECK_MESSAGE (opt.piles == 0, "the default value for piles should be 0");
  CHECK_MESSAGE (opt.stones == 0, "the default value for stones should be 0");
}


