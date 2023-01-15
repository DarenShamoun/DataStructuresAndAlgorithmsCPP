#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <limits>
#include <doctest.h>
#include "../src/rational.h"


SCENARIO( "convert a rational to a double") {
  //      CHECK (275 == doctest::Approx(actual));
  GIVEN ("a valid rational number") {
    WHEN("the rational is 0") {
      rational r {0};
      THEN( "the value should convert to 0" ) {
        REQUIRE (r.to_double() == 0);
        REQUIRE (double(r) == 0);
      }
    }
    WHEN("the rational is 1/2") {
      rational r {1,2};
      THEN( "the value should convert to 0.5" ) {
        REQUIRE (r.to_double() == doctest::Approx(0.5));
        REQUIRE (double(r) == doctest::Approx(0.5));
      }
    }
    WHEN("the rational is {-22,7}") {
      rational r {-22,7};
      THEN( "the value should convert to -pi" ) {
        REQUIRE (r.to_double() == doctest::Approx(-3.14).epsilon(0.01));
        REQUIRE (double(r) == doctest::Approx(-3.14).epsilon(0.01));
      }
    }
    WHEN("the rational is const") {
      const rational r {1,2};
      THEN( "the value should convert to 0.5" ) {
        REQUIRE (r.to_double() == doctest::Approx(0.5));
        REQUIRE (double(r) == doctest::Approx(0.5));
      }
    }
  }
}

SCENARIO ("test invariants of to_double") {
  GIVEN ("a rational number with denominator 0") {
    WHEN("the numerator is 1") {
      rational r {1,0};
      THEN( "the value should convert +inf" ) {
        REQUIRE (r.to_double() == std::numeric_limits<double>::infinity());
      }
    }
    WHEN("the numerator is 0") {
      rational r {0,0};
      THEN( "the value should convert +inf" ) {
        REQUIRE (r.to_double() == std::numeric_limits<double>::infinity());
      }
    }
  }
}

