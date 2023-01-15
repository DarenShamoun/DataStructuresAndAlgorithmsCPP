#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cstdint>
#include <doctest.h>
#include "../src/lab8.h"

SCENARIO( "Compute the apothem of a polygon") {

  GIVEN( "a valid polygon" ) {
    WHEN( "the length of each side is 1 and number of side is 3" ) {
      THEN( "the apothem should be 4.5" ) {
        REQUIRE( mesa::apothem<double, 3>(1) == doctest::Approx(0.28867));
      }
    }
    WHEN( "the length of each side is 3.2 and number of side is 5" ) {
      THEN( "the apothem should be 2.2022" ) {
        CHECK( mesa::apothem<float, 5>(3.2F) == doctest::Approx(2.2022));
      }
    }
    WHEN( "the length of each side is 5 and number of side is 8" ) {
      THEN( "the apothem should be 6.03554" ) {
        CHECK( mesa::apothem<double, 8>(uint64_t(5)) == doctest::Approx(6.03554));
      }
    }
  }
}

SCENARIO( "Compute the invariants of apothem") {

  GIVEN( "an invalid polygon" ) {
    WHEN( "the length of each side is 0 and number of sides is 3" ) {
      THEN( "the apothem should be 0" ) {
        CHECK( mesa::apothem<double, 3>(0)  == doctest::Approx(0));
      }
    }
    WHEN( "the length of each side is 1 and number of sides is 0" ) {
      THEN( "the apothem should be 0" ) {
        CHECK( mesa::apothem<double, 0>(unsigned(1))  == doctest::Approx(0));
      }
    }
    WHEN( "both length of each side and number of sides is 0" ) {
      THEN( "the apothem should be 0" ) {
        CHECK( mesa::apothem<double, 0>(0)  == doctest::Approx(0));
      }
    }
    WHEN( "the length of each side is 1 and number of sides is 2" ) {
      THEN( "the apothem should be 0" ) {
        CHECK( mesa::apothem<double, 2>(1)  == doctest::Approx(0));
      }
    }
    WHEN( "the length of each side is -13 and number of sides is 7" ) {
      THEN( "the apothem should be 0" ) {
        CHECK( mesa::apothem<double, 7>(-13)  == doctest::Approx(0));
      }
    }
    WHEN( "the length of each side is -1 and number of sides is -13" ) {
      THEN( "the apothem should be 0" ) {
        CHECK( mesa::apothem<double, -13>(-1)  == doctest::Approx(0));
      }
    }
  }
}






