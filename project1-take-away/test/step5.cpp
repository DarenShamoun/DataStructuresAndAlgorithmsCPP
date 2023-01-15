#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cstring>

#include <doctest.h>
#include "../src/options.h"

using mesa::option;
//
// For these tests to compile,
// a function signature
// mesa::option get_options (int, char**);
// needs to exist.
//

TEST_CASE( "test -h argument") {
  const char* args[2] = {"test_prog", "-h"};
  auto actual = get_options (2, const_cast<char**>(args));
  option expected;
  expected.valid = false;
  CHECK_MESSAGE(actual.valid == expected.valid,
		  "when the arg is -h, valid should be false");
}


TEST_CASE( "test -c argument") {
  const char* args[2] = {"test_prog", "-c"};
  auto actual = get_options (2, const_cast<char**>(args));
  option expected;
  expected.valid = true;
  expected.has_ai = true;
  CHECK_MESSAGE(actual.has_ai == expected.has_ai,
		  "when the arg is -c, has_ai should be true");
  CHECK_MESSAGE(actual.valid == expected.valid,
		  "when the arg is -c, valid should be true");
}


TEST_CASE( "test -p argument") {
  const char* args[3] = {"test_prog", "-p", "7"};
  auto actual = get_options (3, const_cast<char**>(args));
  option expected;
  expected.valid = true;
  expected.piles = 7;
  CHECK_MESSAGE(actual.piles == expected.piles,
		  "when the arg is -p, piles should be set to the value that follows");
  CHECK_MESSAGE(actual.valid == expected.valid,
		  "when the arg is -p, valid should be true");
}


TEST_CASE( "test invalid -p argument (zero)") {
  const char* args[3] = {"test_prog", "-p", "0"};
  auto actual = get_options (3, const_cast<char**>(args));
  option expected;
  expected.valid = false;
  CHECK_MESSAGE(actual.valid == expected.valid,
		  "when the arg is -p, valid should be false (too few piles)");
}


TEST_CASE( "test invalid -p argument (100)") {
  const char* args[3] = {"test_prog", "-p", "100"};
  auto actual = get_options (3, const_cast<char**>(args));
  option expected;
  expected.valid = false;
  CHECK_MESSAGE(actual.valid == expected.valid,
		  "when the arg is -p, valid should be false (too many piles)");
}


TEST_CASE( "test invalid -p argument (missing)") {
  const char* args[2] = {"test_prog", "-p"};
  auto actual = get_options (2, const_cast<char**>(args));
  option expected;
  expected.valid = false;
  CHECK_MESSAGE(actual.valid == expected.valid,
		  "when the arg is -p, valid should be false (no piles specified)");
}



TEST_CASE( "test -s argument") {
  const char* args[3] = {"test_prog", "-s", "7"};
  auto actual = get_options (3, const_cast<char**>(args));
  option expected;
  expected.valid = true;
  expected.stones = 7;
  CHECK_MESSAGE(actual.stones == expected.stones,
		  "when the arg is -s, stones should be set to the value that follows");
  CHECK_MESSAGE(actual.valid == expected.valid,
		  "when the arg is -s, valid should be true");
}


TEST_CASE( "test invalid -s argument (zero)") {
  const char* args[3] = {"test_prog", "-s", "0"};
  auto actual = get_options (3, const_cast<char**>(args));
  option expected;
  expected.valid = false;
  CHECK_MESSAGE(actual.valid == expected.valid,
		  "when the arg is -s, valid should be false (too few stones)");
}


TEST_CASE( "test invalid -s argument (100)") {
  const char* args[3] = {"test_prog", "-s", "100"};
  auto actual = get_options (3, const_cast<char**>(args));
  option expected;
  expected.valid = false;
  CHECK_MESSAGE(actual.valid == expected.valid,
		  "when the arg is -s, valid should be false (too many stones)");
}


TEST_CASE( "test invalid -s argument (missing)") {
  const char* args[2] = {"test_prog", "-s"};
  auto actual = get_options (2, const_cast<char**>(args));
  option expected;
  expected.valid = false;
  CHECK_MESSAGE(actual.valid == expected.valid,
		  "when the arg is -s, valid should be false (no stones specified)");
}


