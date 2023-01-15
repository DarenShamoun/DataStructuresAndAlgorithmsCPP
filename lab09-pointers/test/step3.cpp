#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cstddef>
#include <iostream>
#include <string>

#include <doctest.h>
#include <lab9.h>

using std::string;

static void do_check(string orig) {
  THEN( "an exact copy should be created on the free store" ) {
    const char* expected = orig.c_str();
    auto actual = mesa::copy(&orig[0], orig.size());
    REQUIRE_MESSAGE(actual != expected, "copied object has the same address as the original");
    INFO ( "Actual: '" << actual << "', Expected: '" << expected << "'." );
    for (int i = 0; expected[i]; ++i) {
      CAPTURE (i);
      REQUIRE_MESSAGE (actual[i] == expected[i], 
              "'" << actual[i] << "' received, '" << expected[i] << "' expected");
    }
    delete[] actual;
  }
}

SCENARIO( "Copy C string") {

  GIVEN( "a valid C string" ) {
    WHEN( "'howdy alice' is provided" ) {
      do_check("howdy alice");
    }
    WHEN( "'bye bob' is provided" ) {
      do_check("bye bob");
    }
    WHEN( "'The rain in Spain' is provided" ) {
      do_check("The rain in Spain");
    }
    WHEN( "'~!@#$-09876asdf;lkj' is provided" ) {
      do_check("~!@#$-09876asdf;lkj");
    }
  }

  GIVEN( "a C string with only null" ) {
    WHEN( "'\0' (null) is provided" ) {
      do_check("\0");
    }
  }

}


