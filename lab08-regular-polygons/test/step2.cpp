#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/lab8.h"

SCENARIO( "Verify area is constexpr") {
  GIVEN( "a valid circle" ) {
    constexpr double mesa_test_pi = 3.1415926535897932384626433832795;
    WHEN( "the function is called" ) {
      THEN( "the return value can be assigned to a constexpr variable" ) {
        constexpr double result = mesa::area(1);
        // a test is redundant, but silences a warning
        // This is really a compiler test
        REQUIRE( result == doctest::Approx(mesa_test_pi));
      }
    }
  }
}

SCENARIO( "Compute the area of a circle") {

  GIVEN( "a circle of radius > 0" ) {
    constexpr double mesa_test_pi = 3.1415926535897932384626433832795;
    WHEN( "1 is provided" ) {
      THEN( "PI should be returned" ) {
        REQUIRE( mesa::area(1) == doctest::Approx(mesa_test_pi));
      }
    }
    WHEN( "2 is provided" ) {
      THEN( "4*PI should be returned" ) {
        CHECK( mesa::area(2) == doctest::Approx(4.*mesa_test_pi));
      }
    }
    WHEN( "8.5 is provided" ) {
      THEN( "226.98 should be returned" ) {
        CHECK( mesa::area(8.5) == doctest::Approx(226.98));
      }
    }
    WHEN( "13.21 is provided" ) {
      THEN( "548.221 should be returned" ) {
        CHECK( mesa::area(13.21) == doctest::Approx(548.221));
      }
    }
  }
}

SCENARIO( "Compute the invariants of circle area") {

  GIVEN( "a circle of radius <= 0" ) {
    WHEN( "0 is provided" ) {
      THEN( "0 should be returned" ) {
        REQUIRE( mesa::area(0) == 0);
      }
    }
    WHEN( "-2 is provided" ) {
      THEN( "0 should be returned" ) {
        CHECK( mesa::area(-2) == 0);
      }
    }
    WHEN( "-8.5 is provided" ) {
      THEN( "0 should be returned" ) {
        CHECK( mesa::area(-8.5) == 0);
      }
    }

  }
}




