#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/lab8.h"

SCENARIO( "Compute the area of a polygon") {

  GIVEN( "a valid polygon" ) {
    WHEN( "the length of each side is 1 and number of sides is 3" ) {
      THEN( "the area should be 3" ) {
        REQUIRE( mesa::area<int, 3>(1) == doctest::Approx(0.433013));
      }
    }
    WHEN( "the length of each side is 3.2 and number of sides is 5" ) {
      THEN( "the area should be about 17.6177" ) {
        CHECK( mesa::area<float, 5>(3.2F) == doctest::Approx(17.6177));
      }
    }
    WHEN( "the length of each side is 5.8 and number of sides is 13" ) {
      THEN( "the area should be about 443.57" ) {
        CHECK( mesa::area<double, 13>(5.8) == doctest::Approx(443.57));
      }
    }
  }
}


SCENARIO( "Compute the invariants of area") {

  GIVEN( "an invalid polygon" ) {
    WHEN( "the length of each side is 0 and number of sides is 3" ) {
      THEN( "the area should be 0" ) {
        REQUIRE( mesa::area<double, 3>(0)  == doctest::Approx(0));
      }
    }
    WHEN( "the length of each side is 1 and number of sides is 0" ) {
      THEN( "the area should be 0" ) {
        CHECK( mesa::area<double, 0>(1)  == doctest::Approx(0));
      }
    }
    WHEN( "both length of each side and number of sides is 0" ) {
      THEN( "the area should be 0" ) {
        CHECK( mesa::area<double, 0>(0)  == doctest::Approx(0));
      }
    }
    WHEN( "the length of each side is 1 and number of sides is 2" ) {
      THEN( "the area should be 0" ) {
        CHECK( mesa::area<double, 2>(1)  == doctest::Approx(0));
      }
    }
    WHEN( "the length of each side is -13 and number of sides is 7" ) {
      THEN( "the area should be 0" ) {
        CHECK( mesa::area<double, 7>(-13)  == doctest::Approx(0));
      }
    }
    WHEN( "the length of each side is -1 and number of sides is -13" ) {
      THEN( "the area should be 0" ) {
        CHECK( mesa::area<double, -13>(-1)  == doctest::Approx(0));
      }
    }
  }
}






