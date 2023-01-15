#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cstdint>
#include <doctest.h>
#include "../src/rational.h"

SCENARIO( "Test rational construction") {
  GIVEN( "a default rational" ) {
    rational r;
    THEN( "the default value should be 0" ) {
      REQUIRE (r.numerator() == 0);
      REQUIRE (r.denominator() == 1);
    }
  }
}



