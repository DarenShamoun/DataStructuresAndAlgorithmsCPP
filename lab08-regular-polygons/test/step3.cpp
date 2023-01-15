#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/lab8.h"

SCENARIO( "Compute the perimeter of a polygon") {

  GIVEN( "a valid polygon" ) {
    WHEN( "the length of each side is 1 and number of side is 3" ) {
      THEN( "the perimeter should be 3" ) {
        REQUIRE( mesa::perimeter(1,3)  == doctest::Approx(3));
      }
    }
    WHEN( "the length of each side is 2.71828 and number of side is 3" ) {
      THEN( "the perimeter should be 8.1548" ) {
        CHECK( mesa::perimeter(2.71828,3)  == doctest::Approx(8.1548));
      }
    }
    WHEN( "the length of each side is 5 and number of side is 13" ) {
      THEN( "the perimeter should be 65" ) {
        CHECK( mesa::perimeter(unsigned(5),13)  == 65);
      }
    }
  }
}


SCENARIO( "Compute the invariants of perimeter") {

  GIVEN( "an invalid polygon" ) {
    WHEN( "the length of each side is 0 and number of side is 3" ) {
      THEN( "the perimeter should be 0" ) {
        REQUIRE( mesa::perimeter(0,3)  == doctest::Approx(0));
      }
    }
    WHEN( "the length of each side is 1 and number of sides is 0" ) {
      THEN( "the perimeter should be 0" ) {
        CHECK( mesa::perimeter(1,0)  == doctest::Approx(0));
      }
    }
    WHEN( "both length of each side and number of sides is 0" ) {
      THEN( "the perimeter should be 0" ) {
        CHECK( mesa::perimeter(0,0)  == doctest::Approx(0));
      }
    }
    WHEN( "the length of each side is 1 and number of sides is 2" ) {
      THEN( "the perimeter should be 0" ) {
        CHECK( mesa::perimeter(1,2)  == doctest::Approx(0));
      }
    }
    WHEN( "the length of each side is -13 and number of sides is 7" ) {
      THEN( "the perimeter should be 0" ) {
        CHECK( mesa::perimeter(-13, 7)  == doctest::Approx(0));
      }
    }
    WHEN( "the length of each side is -1 and number of sides is -13" ) {
      THEN( "the perimeter should be 0" ) {
        CHECK( mesa::perimeter(-1, -13)  == doctest::Approx(0));
      }
    }
  }
}

